//
// Created by haram on 2023-09-16
//
// Problem-Solving #22938
#include <iostream>

using namespace std;
long long x1, y1, r1;
long long x2, y2, r2;
int main(){
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    unsigned long long dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    unsigned long long dist2 = (r1 + r2) * (r1 + r2);
    if(dist >= dist2)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}