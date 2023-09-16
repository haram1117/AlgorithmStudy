//
// Created by haram on 2023-09-16
//
// Problem-Solving #27110
#include <iostream>

using namespace std;
int n;
int a, b, c;
int main(){
    cin >> n;
    cin >> a >> b >> c;
    cout << min(a, n) + min(b, n) + min(c, n);
    return 0;
}