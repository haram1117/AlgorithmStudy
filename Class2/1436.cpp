//
// Created by haram on 2023-03-15.
//
#include <iostream>
using namespace std;
int n;
int num = 665;

int main(){
    cin >> n;
    int cnt = 0;
    while(cnt != n){
        num++;
        if(to_string(num).find("666") != string::npos){
            cnt++;
        }
    }
    cout << num;
    return 0;
}