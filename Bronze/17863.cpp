//
// Created by haram on 2023-09-09
//
// Problem-Solving #17863
#include <iostream>

using namespace std;
string s;
int main(){
    cin >> s;
    if(s[0] == '5' && s[1] == '5' && s[2] == '5')
        cout << "YES";
    else
        cout << "NO";
    return 0;
}