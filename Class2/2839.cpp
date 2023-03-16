//
// Created by haram on 2023-03-16.
//
#include <iostream>

using namespace std;
int n;
int result = 5000;
int main(){
    cin >> n;
    for(int i = 0; i < n / 3; i++){
        int tmp = 0;
        int num = n;
        if(num % 5 == 0){
            tmp += num / 5;
            result = min(result, tmp);
        }
        for(int j = 0; j <= i; j++){
            num -= 3;
            tmp++;
            if(num % 5 == 0){
                tmp += num / 5;
                result = min(result, tmp);
            }
        }
    }
    if(result == 5000)
        result = -1;
    cout << result;
    return 0;
}