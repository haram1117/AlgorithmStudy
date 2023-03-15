//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;
int x, y, w, h;
int result;
int main(){
    cin >> x >> y >> w >> h;
    result = min(x, y);
    result = min(result, w - x);
    result = min(result, h - y);
    cout << result;
    return 0;
}