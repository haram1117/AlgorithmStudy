//
// Created by haram on 2023-09-15
//
// Problem-Solving #20332
#include <iostream>

using namespace std;

int n;
unsigned long long sum;
int main(){
    cin >> n;
    int tmp;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        sum += tmp;
    }

    if(sum % 3 == 0)
        cout << "yes";
    else
        cout << "no";
    return 0;
}