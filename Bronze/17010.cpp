//
// Created by haram on 2023-09-09
//
// Problem-Solving #17010
#include <iostream>

using namespace std;
int l;
int main(){
    cin >> l;
    for(int i = 0; i < l; ++i){
        int num;
        char ch;
        cin >> num >> ch;
        for(int k = 0; k < num; ++k)
            cout << ch;
        cout << '\n';
    }

    return 0;
}