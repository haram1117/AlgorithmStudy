//
// Created by haram on 2023-09-09
//
// Problem-Solving #17530
#include <iostream>

using namespace std;
int n;
int M;
int car;
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        if(i == 0)
            car = tmp;
        M = max(M, tmp);
    }
    if(car == M)
        cout << 'S';
    else
        cout << 'N';

    return 0;
}