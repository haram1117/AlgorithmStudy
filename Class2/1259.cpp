//
// Created by haram on 2023-03-15.
//
#include <iostream>
using namespace std;

bool solve(string str){
    auto it = str.begin();
    auto rit = str.rbegin();
    while(it != str.end()){
        if(*it != *rit)
            return false;
        it++, rit++;
    }
    return true;
}

int main(){
    while(cin){
        string tmp;
        cin >> tmp;
        if(tmp == "0")
            break;
        if(solve(tmp))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}