//
// Created by haram on 2023-09-09
//
// Problem-Solving #17094
#include <iostream>

using namespace std;
int len;
string s;
int main(){
    cin >> len >> s;
    int cnt = 0;
    for(auto const & elem : s){
        if(elem == '2')
            cnt++;
    }
    if(cnt > len - cnt)
        cout << 2;
    else if(cnt < len - cnt)
        cout << 'e';
    else
        cout << "yee";
    return 0;
}