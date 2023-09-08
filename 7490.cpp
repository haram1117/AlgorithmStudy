//
// Created by haram on 2023-09-08
//
// Problem-Solving #7490
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int t, n;

bool isZero(string s){
    stack<string> stack1;

    bool check = false;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == ' '){
            check = true;
        }
        else{
            if(check){
                string newS = stack1.top();
                newS += s[i];
                stack1.pop();
                stack1.emplace(newS);
                check = false;
            }
            else{
                string s1 = "";
                s1 += s[i];
                stack1.emplace(s1);
            }
        }
    }

    stack<string> stack2;
    while(!stack1.empty()){
        stack2.emplace(stack1.top());
        stack1.pop();
    }

    int num = 0;
    int plus = 1;
    while(!stack2.empty()){
        if(stack2.top() == "+")
            plus = 1;
        else if(stack2.top() == "-")
            plus = -1;
        else
            num += stoi(stack2.top()) * plus;
        stack2.pop();
    }
    if(num == 0)
        return true;
    return false;
}

void dfs(string s, int curr){
    s += curr + '0';

    if(curr == n){
        if(isZero(s)){
            cout << s << '\n';
        }
        return;
    }

    dfs(s + " ", curr + 1);
    dfs(s + "+", curr + 1);
    dfs(s + "-", curr + 1);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--){
        cin >> n;
        string s = "1";
        dfs(s + " ", 2);
        dfs(s + "+", 2);
        dfs(s + "-", 2);

        cout << '\n';
    }

    return 0;
}