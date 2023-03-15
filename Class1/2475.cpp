//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;

int sum;
int main(){
    for(int i = 0; i < 5; i++){
        int tmp;
        cin >> tmp;
        sum += tmp * tmp;
    }
    cout << sum % 10;
    return 0;
}