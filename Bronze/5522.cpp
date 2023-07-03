//
// Created by haram on 2023-06-29.
//
#include <iostream>

using namespace std;

int main(){
    int result = 0;
    for(int i = 0; i < 5; ++i){
        int tmp;
        cin >> tmp;
        result += tmp;
    }
    cout << result;
    return 0;
}