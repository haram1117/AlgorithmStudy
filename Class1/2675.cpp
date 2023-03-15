//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;
int t;

void solve(int r, string s){
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < r; j++)
            cout << s[i];
    }
    cout << '\n';
}

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        int r;
        string s;
        cin >> r >> s;
        solve(r, s);
    }

    return 0;
}