//
// Created by haram on 2023-02-07.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    long long n;
    int b;
    cin >> n >> b;

    string result = "";

    while(n / b >= 1){
        char ch;
        if(n % b >= 10){
            ch = ((n % b) - 10) + 'A';
        }
        else{
            ch = (n % b) + '0';
        }
        n /= b;
        result = ch + result;
    }
    char tmp;
    if(n >= 10)
        tmp = (n - 10) + 'A';
    else
        tmp = n + '0';
    result = tmp + result;
    cout << result;

    return 0;
}