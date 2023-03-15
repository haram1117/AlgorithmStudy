//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;
bool info[42];
int result;
int main(){
    for(int i = 0; i < 10; i++){
        int tmp;
        cin >> tmp;
        if(!info[tmp % 42]){
            info[tmp % 42] = true;
            result++;
        }
    }
    cout << result;
    return 0;
}