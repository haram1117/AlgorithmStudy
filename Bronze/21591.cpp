//
// Created by haram on 2023-09-15
//
// Problem-Solving #21591
#include <iostream>

using namespace std;

int wc, hc, w_s, hs;
int main(){
    cin >> wc >> hc >> w_s >> hs;

    if(wc > w_s + 1 && hc > hs + 1)
        cout << 1;
    else
        cout << 0;

    return 0;
}