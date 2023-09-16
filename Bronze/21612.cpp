//
// Created by haram on 2023-09-16
//
// Problem-Solving #21612
#include <iostream>

using namespace std;
int b;
int main(){
    cin >> b;
    int result = 5 * b - 400;
    cout << result << '\n';
    if(result == 100)
        cout << 0;
    else if(result > 100)
        cout << -1;
    else
        cout << 1;
    return 0;
}