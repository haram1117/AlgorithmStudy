//
// Created by haram on 2023-03-18.
//
#include <iostream>

using namespace std;

int main(){
    string input;
    cin >> input;
    for(auto &elem : input){
        if(elem >= 'a' && elem <= 'z')
            elem += 'A' - 'a';
        else
            elem += 'a' - 'A';
    }
    cout << input;
    return 0;
}