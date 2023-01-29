//
// Created by haram on 2023-01-29.
//

#include <iostream>

using namespace std;

/*
 * 소수 구하기
 * 루트 n 보다 작은 자연수들로 나눠봤을때, 나누어 떨어지는 자연수가 없으면 소수다
 * */
bool isPrime(int n){
    if(n < 2)
        return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    int m, n;
    cin >> m >> n;

    for(int i = m; i <= n; i++){
        if(isPrime(i))
            cout << i << "\n";
    }
    return 0;
}