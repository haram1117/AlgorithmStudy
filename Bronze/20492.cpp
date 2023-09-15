//
// Created by haram on 2023-09-15
//
// Problem-Solving #20492
#include <iostream>

using namespace std;
int n;
int main(){
    cin >> n;
    cout << (n / 100) * 78 << '\n';
    cout << (n / 10) * 8 + (n / 10 * 2) / 100 * 78;
    return 0;
}