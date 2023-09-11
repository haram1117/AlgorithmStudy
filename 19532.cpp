//
// Created by haram on 2023-09-11
//
// Problem-Solving #19532
#include <iostream>

using namespace std;
int a, b, c, d, e, f;
int x, y;
int main(){
    cin >> a >> b >> c >> d >> e >> f;

    y = (c * d - f * a) / (b * d - a * e);
    x = (c * e - f * b) / (a * e - b * d);

    cout << x  << " " << y;

    return 0;
}