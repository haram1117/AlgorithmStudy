//
// Created by haram on 2023-03-16.
//
#include <iostream>

using namespace std;
int main(){
    int n;
    cin >> n;
    int tmp = 1;
    int idx = 0;
    while(true){
        tmp += 6 * idx;
        idx++;
        if(tmp >= n){
            break;
        }
    }
    cout << idx;
    return 0;
}