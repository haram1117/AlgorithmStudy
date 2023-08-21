//
// Created by haram on 2023-08-21
//
// Problem-Solving #14038
#include <iostream>

using namespace std;
int win;
int main(){
    for(int i = 0; i < 6; ++i){
        char tmp;
        cin >> tmp;
        if(tmp == 'W')  win++;
    }
    if(win == 5 || win == 6)    cout << 1;
    else if(win == 3 || win == 4) cout << 2;
    else if(win == 1 || win == 2) cout << 3;
    else
        cout << -1;
    return 0;
}