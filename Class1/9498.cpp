//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;
int num;
int main(){
    cin >> num;
    if(num >= 90 && num <= 100)
        cout << 'A';
    else if(num >= 80 && num <= 89)
        cout << 'B';
    else if(num >= 70 && num <= 79)
        cout << 'C';
    else if(num >= 60 && num <= 69)
        cout << 'D';
    else
        cout << 'F';
    return 0;
}