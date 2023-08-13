//
// Created by haram on 2023-08-13
//
// Problem-Solving #A
#include <iostream>

using namespace std;

int n;
int result1, result2;
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        result1 += i;
        result2 += i * i * i;
    }
    cout << result1 << "\n" << result1 * result1 << "\n" << result2;

    return 0;
}