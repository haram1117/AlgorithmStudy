//
// Created by haram on 2023-09-10
//
// Problem-Solving #18398
#include <iostream>

using namespace std;
int t;
int main(){
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int a, b;
            cin >> a >> b;
            cout << a + b << " " << a * b << '\n';
        }
    }
    return 0;
}