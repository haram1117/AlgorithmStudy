//
// Created by haram on 2023-03-16.
//
#include <iostream>
#include <stack>
using namespace std;
int k;
int main(){
    cin >> k;
    int sum = 0;
    stack<int> stack1;
    for(int i = 0; i < k; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            sum -= stack1.top();
            stack1.pop();
        }
        else{
            sum += tmp;
            stack1.push(tmp);
        }
    }
    cout << sum;
    return 0;
}