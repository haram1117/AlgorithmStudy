//
// Created by haram on 2023-07-06
//
// Problem-Solving #11549

#include <iostream>

using namespace std;
int t, num, result;

int main(){
    cin >> t;
    for(int i = 0; i < 5; ++i){
        cin >> num;
        if(num == t)
            result++;
    }
    cout << result;

    return 0;
}