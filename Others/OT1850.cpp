//
// Created by haram on 2023-01-29.
//

#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    return a % b ? gcd(b, a % b) : b;
}


int main(){
    long long a, b;
    cin >> a >> b;

    long long result = gcd(a, b);
    for(int i = 0; i < result; i++){
        cout << "1";
    }
}