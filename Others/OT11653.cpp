//
// Created by haram on 2023-02-15.
//

#include <iostream>
using namespace std;

int canDivide(int& n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            n /= i;
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;

    if(n == 1)
        return 0;

    int tmp = 0;
    while(true){
        tmp = canDivide(n);
        if(tmp == -1){
            cout << n << '\n';
            break;
        }
        cout << tmp << '\n';
    }

    return 0;
}