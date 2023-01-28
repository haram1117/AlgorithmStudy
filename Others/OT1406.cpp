//
// Created by haram on 2023-01-28.
//
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string inputStr;
    int num;

    cin >> inputStr >> num;

    stack<char> left;
    stack<char> right;

    for(char i : inputStr)
        left.push(i);

    for(int i = 0; i < num; i++){
        char tmp;
        cin >> tmp;
        if(tmp == 'P'){
            char tmp2;
            cin >> tmp2;
            tmp = tmp2;
        }
        if(tmp == 'L'){
            if(left.empty())
                continue;
            right.push(left.top());
            left.pop();
        }
        else if(tmp == 'D'){
            if(right.empty())
                continue;
            left.push(right.top());
            right.pop();
        }
        else if(tmp == 'B'){
            if(left.empty())
                continue;
            left.pop();
        }
        else{
            left.push(tmp);
        }
    }

    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()){
        cout << right.top();
        right.pop();
    }

    return 0;
}