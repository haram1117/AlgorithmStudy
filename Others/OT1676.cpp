//
// Created by haram on 2023-01-28.
//
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    n -= n % 5;
    int result = n / 5;
    result += n / 25;
    result += n / 125;

    cout << result;

    return 0;
}