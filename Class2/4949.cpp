//
// Created by haram on 2023-03-16.
//
#include <iostream>
#include <stack>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(cin){
        string str;
        stack<char> stack1;
        getline(cin, str);
        if(str == ".")
            break;
        bool check = true;
        for(auto elem : str){
            if(elem == '('){
                stack1.push('(');
            }
            else if(elem == ')'){
                if(stack1.empty()){
                    check = false;
                    break;
                }
                if(stack1.top() == '('){
                    stack1.pop();
                }
                else{
                    check = false;
                    break;
                }
            }
            if(elem == '['){
                stack1.push('[');
            }
            else if(elem == ']'){
                if(stack1.empty()){
                    check = false;
                    break;
                }
                if(stack1.top() == '['){
                    stack1.pop();
                }
                else{
                    check = false;
                    break;
                }
            }
        }
        if(!stack1.empty() || !check)
            cout << "no\n";
        else
            cout << "yes\n";
    }
    return 0;
}