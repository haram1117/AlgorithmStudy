//
// Created by haram on 2023-09-16
//
// Problem-Solving #25238
#include <iostream>

using namespace std;
int a, b;
int main(){
    cin >> a >> b;

    int result = 100 * a - a * b;

    if(result >= 10000)
        cout << 0;
    else
        cout << 1;

    return 0;
}