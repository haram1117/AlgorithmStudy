//
// Created by haram on 2023-02-08.
//
#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

int main(){
    int a, b, m;
    cin >> a >> b >> m;
    int input[m];
    for(int i = 0; i < m ; i++){
        cin >> input[i];
    }
    long long value = 0;
    for(int i = 0; i < m; i++){
        value += input[i] * pow(a, m - i - 1);
    }

    stack<int> stack1;
    while(value / b >= 1){
        stack1.push(value % b);
        value /= b;
    }
    stack1.push(value);

    while(!stack1.empty()){
        cout << stack1.top() << " ";
        stack1.pop();
    }


    return 0;
}