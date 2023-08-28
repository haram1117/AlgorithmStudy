//
// Created by haram on 2023-08-28
//
// Problem-Solving #15000
#include <iostream>

using namespace std;
string s;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;
    for(auto & elem : s){
        elem = 'A' + (elem - 'a');
    }
    cout << s;
    return 0;
}