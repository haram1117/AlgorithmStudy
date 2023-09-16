//
// Created by haram on 2023-09-16
//
// Problem-Solving #27294
#include <iostream>

using namespace std;
int t, s;
int main(){
    cin >> t >> s;
    if(s == 1 || (t <= 11 || t > 16)){
        cout << 280;
    }
    else{
        cout << 320;
    }
    return 0;
}