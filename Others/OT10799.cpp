//
// Created by haram on 2023-02-01.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> input;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int result = 0;
    bool check = false;
    string inputStr;
    cin >> inputStr;

    for (auto tmp: inputStr) {
        if(tmp == '('){
            input.push(tmp);
            check = true;
        }
        else{
            if(check){
                input.pop();
                result += input.size();
            }else{
                input.pop();
                result++;
            }
            check = false;
        }
    }

    cout << result;

    return 0;
}