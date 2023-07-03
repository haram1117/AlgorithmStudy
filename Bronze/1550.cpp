//
// Created by haram on 2023-06-29.
//
#include <iostream>
#include <math.h>

using namespace std;
string a;
int result;

int main(){
    cin >> a;

    for(int i = 0; i < a.length(); ++i){
        int tmp;
        if(a[i] >= '0' && a[i] <= '9')
            tmp = a[i] - '0';
        else
            tmp = a[i] - 'A' + 10;
        result += pow(16, (a.length() - i - 1)) * tmp;
    }

    cout << result;

    return 0;
}