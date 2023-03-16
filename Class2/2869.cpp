//
// Created by haram on 2023-03-16.
//
#include <iostream>

using namespace std;
int a, b, v;
int result;

int main(){
    cin >> a >> b >> v;
    int n = a - b;

    result = (v - b) / n;

    if((v - b) % n != 0)
        result++;

    cout << result;
    return 0;
}