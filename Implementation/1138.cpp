//
// Created by haram on 2023-08-24
//
// Problem-Solving #1138
#include <iostream>

using namespace std;
int n;
int info[10];
int main(){

    cin >> n;

    int tmp;
    for(int i = 1; i <= n; ++i){
        cin >> tmp;
        int idx = -1;
        for(int j = 0; j < n; ++j){
            if(info[j] == 0)
                idx++;
            if(tmp == idx){
                info[j] = i;
                break;
            }
        }
    }

    for(int i = 0; i < n; ++i)
        cout << info[i] << " ";

    return 0;
}