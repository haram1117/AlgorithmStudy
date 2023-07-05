//
// Created by haram on 2023-07-05
//
// Problem-Solving #6810

#include <iostream>

using namespace std;
int a, b, c;
int result = 0;
string ten_digit = "9780921418";

int main(){
    cin >> a >> b >> c;

    for(int i = 0; i < 10; i += 2){
        result += (ten_digit[i] - '0');
        result += (ten_digit[i + 1] - '0') * 3;
    }

    result += a;
    result += b * 3;
    result += c;

    cout << "The 1-3-sum is " << result;

    return 0;
}
