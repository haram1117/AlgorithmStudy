//
// Created by haram on 2023-09-07
//
// Problem-Solving #17009
#include <iostream>

using namespace std;
int a1, b1, c1;
int a2, b2, c2;
int main(){
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    int sub = 3 * (a1 - a2) + 2 * (b1 - b2) + (c1 - c2);
    if(sub > 0) cout << 'A';
    else if(sub < 0)    cout << 'B';
    else    cout << 'T';

    return 0;
}