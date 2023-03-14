//
// Created by haram on 2023-03-14.
//
#include <iostream>

using namespace std;
int e, s, m;
int result;
int _e, _s, _m;
int main(){
    cin >> e >> s >> m;
    while(!(e == _e && s == _s && m == _m)){
        _e++;
        _s++;
        _m++;
        if(_e >= 16)
            _e = 1;
        if(_s >= 29)
            _s = 1;
        if(_m >= 20)
            _m = 1;
        result++;
    }
    cout << result;
    return 0;
}