//
// Created by haram on 2023-03-16.
//
#include <iostream>
using namespace std;

int main(){
    int l;
    string str;
    cin >> l >> str;
    long long sum = 0;
    for(int i = 0; i < l; i++){
        long long tmp = 1;
        for(int k = 0; k < i; k++){
            tmp *= 31;
            tmp %= 1234567891;
        }
        sum += (str[i] - 'a' + 1) * tmp;
        sum %= 1234567891;
    }
    cout << sum % 1234567891;
    return 0;
}