//
// Created by haram on 2023-04-07.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;
string input;
string result;
stack<char> s;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input;
    for(const auto & elem : input){
        if(elem == '('){
            s.emplace(elem);
        }
        else if(elem == ')'){
            while(!s.empty()){
                if(s.top() == '('){
                    s.pop();
                    break;
                }
                result += s.top();
                s.pop();
            }
        }
        else if(elem == '*' || elem == '/'){
            if(!s.empty()){
                if(s.top() == '*' || s.top() == '/'){
                    result += s.top();
                    s.pop();
                }
            }
            s.emplace(elem);
        }
        else if(elem == '+' || elem == '-'){
            if(!s.empty()){
                if(s.top() == '('){
                    s.emplace(elem);
                }
                else{
                    while(!s.empty()){
                        if(s.top() != '('){
                            result += s.top();
                            s.pop();
                        }
                        else{
                            break;
                        }
                    }
                    s.emplace(elem);
                }
            }
            else{
                s.emplace(elem);
            }
        }
        else{
            result += elem;
        }
    }
    while(!s.empty()){
        result += s.top();
        s.pop();
    }

    cout << result;

    return 0;
}