//
// Created by haram on 2023-01-31.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){

    string input;
    cin >> input;
    int b;
    cin >> b;

    long long result = 0;
    int num = input.length() - 1;
    for(int i = 0; i < input.length(); i++){
        long long mult = pow(b, num - i);
        if(input[i] >= 48 && input[i] <= 57){
            result += (input[i] - '0') * mult;
        }
        else{
            result += (input[i] - 'A' + 10) * mult;
        }
    }

    cout << result;
    return 0;
}