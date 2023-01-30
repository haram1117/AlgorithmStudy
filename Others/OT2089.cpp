//
// Created by haram on 2023-01-30.
//

#include <iostream>
#include <stack>
using namespace std;

stack<int> result;

void print(int val){
    if(val == 1)
        result.push(1);
    else if(val == -1)
        result.push(11);
    else if(val == 0)
        result.push(0);
}

int main(){
    int n;
    cin >> n;


    while (abs(n) > 1){
        if(n % (-2) == -1){
            n /= (-2);
            n++;
            print(1);
        }
        print(n % (-2));
        n /= (-2);
    }
    print(n);

    while(!result.empty()){
        cout << result.top();
        result.pop();
    }

    return 0;
}