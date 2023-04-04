//
// Created by haram on 2023-04-04.
//
#include <iostream>

using namespace std;
long long a, b, c;

long long result = 1;

long long solve(long long n){
    if(n == 1){
        return a % c;
    }
    else if(n == 0)
        return 1;
    long long tmp = solve(n / 2) % c;
    if(n % 2 == 0){
        return tmp * tmp % c;
    }
    else{
        return ((tmp * tmp) % c) * (a % c) % c;
    }
}


int main(){
    cin >> a >> b >> c;

    result = solve(b);

    cout << result;

    return 0;
}