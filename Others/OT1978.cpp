//
// Created by haram on 2023-01-29.
//
#include <iostream>
using namespace std;

int isPrime(int n){
    if(n < 2)
        return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main(){
    int n;
    cin >> n;

    int result = 0;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;

        if(isPrime(tmp))
            result++;
    }

    cout << result;

    return 0;
}