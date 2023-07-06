//
// Created by haram on 2023-07-06
//
// Problem-Solving #10817

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a, b, c;
vector<int> v(3);
int main(){
    cin >> a >> b >> c;

    v[0] = a;
    v[1] = b;
    v[2] = c;

    sort(v.begin(), v.end());

    cout << v[1];

    return 0;
}