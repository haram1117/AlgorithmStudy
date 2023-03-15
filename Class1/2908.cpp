//
// Created by haram on 2023-03-15.
//
#include <iostream>
#include <math.h>
using namespace std;
int a, b;
int newA, newB;
int main(){
    cin >> a >> b;
    for(int i = 0; i < 3; i++){
        newA += (a % 10) * pow(10, 2 - i);
        newB += (b % 10) * pow(10, 2 - i);
        a /= 10;
        b /= 10;
    }

    cout << max(newA, newB);
    return 0;
}