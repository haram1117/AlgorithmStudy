//
// Created by haram on 2023-01-30.
//
#include <iostream>

using namespace std;

int gcd(int a, int b){
    return a % b ? gcd(b, a % b) : b;
}

int lcm(int a, int b, int gcd){
    return a * b / gcd;
}

int main(){
    int a, b;
    cin >> a >> b;

    int gcdVal = gcd(a, b);
    cout << gcdVal << "\n" << lcm(a, b, gcdVal);
    return 0;
}