//
// Created by haram on 2023-07-06
//
// Problem-Solving #11104

#include <iostream>
#include <math.h>

using namespace std;
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        char tmp;
        int result = 0;
        for(int k = 0; k < 24; ++k){
            cin >> tmp;
            result += pow(2, 24 - k - 1) * (tmp - '0');
        }
        cout << result << '\n';
    }
    return 0;
}