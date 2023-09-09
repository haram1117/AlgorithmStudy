//
// Created by haram on 2023-09-09
//
// Problem-Solving #17388
#include <iostream>

using namespace std;
int s, k, h;
int main(){
    cin >> s >> k >> h;
    if(s + k + h >= 100)
        cout << "OK";
    else{
        int m = min(s, min(k, h));
        if(m == s)
            cout << "Soongsil";
        else if(m == k)
            cout << "Korea";
        else
            cout << "Hanyang";
    }
    return 0;
}