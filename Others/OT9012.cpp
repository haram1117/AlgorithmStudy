//
// Created by haram on 2023-01-31.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        stack<char> input;
        string inputStr;
        cin >> inputStr;
        bool check = false;
        for(int k = 0; k < inputStr.length(); k++){
            char tmp = inputStr[k];
            if(tmp == '(')
                input.push(tmp);
            else{
                if(input.empty()){
                    cout << "NO\n";
                    check = true;
                    break;
                }
                input.pop();
            }
        }
        if(check)
            continue;
        if(input.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}