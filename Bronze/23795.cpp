//
// Created by haram on 2023-09-16
//
// Problem-Solving #23795
#include <iostream>

using namespace std;
int sum;
int main(){
    int tmp;
    while(true){
        cin >> tmp;
        if(tmp == -1)
            break;
        sum += tmp;
    }
    cout << sum;
    return 0;
}