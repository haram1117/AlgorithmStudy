//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;
int num;
int main(){
    cin >> num;
    if(num % 4 == 0){
        if(num % 100 != 0){
            cout << 1;
            return 0;
        }
        else if(num % 400 == 0){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}