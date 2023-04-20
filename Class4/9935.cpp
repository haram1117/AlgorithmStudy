//
// Created by haram on 2023-04-20.
//
#include <iostream>
#include <stack>

using namespace std;
string input;
string bomb;
stack<char> s;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> input >> bomb;

    for(auto const & elem : input){
        s.emplace(elem);
        if(elem == bomb.back()){
            stack<char> tmp;
            for(int i = bomb.size() - 1; i >= 0; --i){
                if(s.empty()){
                    while(!tmp.empty()){
                        s.emplace(tmp.top());
                        tmp.pop();
                    }
                    break;
                }
                if(s.top() == bomb[i]){ // 여기서 s가 empty인지 계속 확인해줘야 함(반례: A, BA)
                    s.pop();
                    tmp.emplace(bomb[i]);
                }
                else{
                    while(!tmp.empty()){
                        s.emplace(tmp.top());
                        tmp.pop();
                    }
                    break;
                }
            }
        }
    }

    if(s.empty())
        cout << "FRULA";
    else{
        stack<char> tmp;
        while(!s.empty()){
            tmp.emplace(s.top());
            s.pop();
        }
        while(!tmp.empty()){
            cout << tmp.top();
            tmp.pop();
        }
    }

    return 0;
}