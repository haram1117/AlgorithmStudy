//
// Created by haram on 2023-08-29
//
// Problem-Solving #15372
#include <iostream>

using namespace std;

long long n;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n;
        cout << n * n << '\n';
    }
    return 0;
}