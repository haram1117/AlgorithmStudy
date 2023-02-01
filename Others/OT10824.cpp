//
// Created by haram on 2023-02-01.
//
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    a *= pow(10, to_string(b).length());
    c *= pow(10, to_string(d).length());
    cout << (a + b) + (c + d);
    return 0;
}