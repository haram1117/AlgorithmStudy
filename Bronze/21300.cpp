//
// Created by haram on 2023-09-15
//
// Problem-Solving #21300
#include <iostream>

using namespace std;

int sum = 0;
int main(){
    int tmp;
    for(int i = 0; i < 6; ++i){
        cin >> tmp;
        sum += tmp * 5;
    }
    cout << sum;
    return 0;
}