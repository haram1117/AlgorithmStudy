//
// Created by haram on 2023-03-16.
//
#include <iostream>

using namespace std;
int n, k;
int main(){
    cin >> n >> k;
    int n1 = 1;
    int n2 = 1;
    for(int i = 0; i < k; i++){
        n1 *= (n - i);
        n2 *= (k - i);
    }
    cout << n1 / n2;
    return 0;
}