//
// Created by haram on 2023-09-16
//
// Problem-Solving #27433
#include <iostream>

using namespace std;
int n;
unsigned long long result = 1;
int main(){
    cin >> n;
    for(int i = n; i >= 1; --i){
        result *= i;
    }
    cout << result;
    return 0;
}