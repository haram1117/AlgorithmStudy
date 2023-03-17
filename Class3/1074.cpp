//
// Created by haram on 2023-03-17.
//
#include <iostream>
#include <math.h>
using namespace std;

int n, r, c;
int main(){
    cin >> n >> r >> c;
    unsigned result = 0;
    while(n >= 1){
        n--;
        int n2 = pow(2, n);
        int interval = n2 * n2;
        if(r >= n2 && c >= n2){
            result += interval * 3;
            r -= n2;
            c -= n2;
        }
        else if(r >= n2 && c < n2){
            result += interval * 2;
            r -= n2;
        }
        else if(r < n2 && c >= n2){
            result += interval;
             c -= n2;
        }
    }
    cout << result;
    return 0;
}