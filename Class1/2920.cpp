//
// Created by haram on 2023-03-15.
//
#include <iostream>
using namespace std;
int input[8];
int main(){
    for(int i = 0; i < 8; i++){
        cin >> input[i];
    }
    bool check = true;
    for(int i = 0; i < 8; i++){
        if(input[i] != i + 1)
            check = false;
    }
    if(check){
        cout << "ascending";
        return 0;
    }

    check = true;
    for(int i = 0; i < 8; i++){
        if(input[i] != 8 - i)
            check = false;
    }
    if(check){
        cout << "descending";
        return 0;
    }

    cout << "mixed";
    return 0;
}