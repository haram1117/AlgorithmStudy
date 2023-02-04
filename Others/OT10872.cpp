//
// Created by haram on 2023-02-04.
//
#include <iostream>

using namespace std;

long long factorial(int x){
    if(x <= 1)
        return 1;
    return x * factorial(x - 1);
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n);
}