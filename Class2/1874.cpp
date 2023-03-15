//
// Created by haram on 2023-03-15.
//
#include <iostream>
#include <stack>

using namespace std;
int n;
int input[100000];
stack<int> stack1;
string result;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    int idx = 0;
    int num = 1;
    stack1.push(num);
    result += "+\n";
    while(idx < n){
        if(stack1.empty() || stack1.top() != input[idx]){
            result += "+\n";
            num++;
            stack1.push(num);
        }
        else{
            stack1.pop();
            result += "-\n";
            idx++;
        }
        if(num > n){
            break;
        }
    }
    if(!stack1.empty()){
        cout << "NO";
        return 0;
    }
    cout << result;
    return 0;
}