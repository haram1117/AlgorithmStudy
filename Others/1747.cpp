//
// Created by haram on 2023-07-14
//
// Problem-Solving #1747

#include <iostream>
using namespace std;
int n;

bool isPrime(int num){
    if(num == 1)    return false;
    for(int i = 2; i * i <= num; ++i){
        if(num % i == 0)
            return false;
    }
    return true;
}

bool palindrome(int num){
    string str = to_string(num);
    for(int i = 0; i < str.length() / 2; ++i){
        if(str[i] != str[str.length() - i - 1])
            return false;
    }
    return true;
}

int main(){
    cin >> n;

    int num = n;
    while(true){
        if(isPrime(num))
            if(palindrome(num))
                break;
        ++num;
    }

    cout << num;

    return 0;
}