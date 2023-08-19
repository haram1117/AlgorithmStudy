//
// Created by haram on 2023-08-19
//
// Problem-Solving #13752
#include <iostream>

using namespace std;
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        for(int k = 0; k < tmp; ++k)
            cout << "=";
        cout << '\n';
    }
    return 0;
} 