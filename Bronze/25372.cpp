//
// Created by haram on 2023-09-16
//
// Problem-Solving #25372
#include <iostream>

using namespace std;
int n;
int main(){
    cin >> n;
    string str;
    while(n--){
        cin >> str;
        if(str.size() >= 6 && str.size() <= 9)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}