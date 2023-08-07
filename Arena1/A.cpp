//
// Created by haram on 2023-08-06
//
// Problem-Solving #A

#include <iostream>

using namespace std;
bool info[10];

int main(){
    int tmp;
    for(int i = 0; i < 5; ++i){
        cin >> tmp;
        if(info[tmp])
            info[tmp] = false;
        else
            info[tmp] = true;
    }
    for(int i = 0; i < 10; ++i)
        if(info[i])
            cout << i;
    return 0;
}