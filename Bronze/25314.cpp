//
// Created by haram on 2023-09-16
//
// Problem-Solving #25314
#include <iostream>

using namespace std;
int n;
int main(){
    cin >> n;
    string ans = "int";
    for(int i = 4; i <= n; i += 4){
        ans = "long " + ans;
    }
    cout << ans;
    return 0;
}