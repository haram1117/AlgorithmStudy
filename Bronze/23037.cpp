//
// Created by haram on 2023-09-16
//
// Problem-Solving #23037
#include <iostream>

using namespace std;

int solve(int num){
    return num * num * num * num * num;
}
string n;
int result;
int main(){
    cin >> n;
    for(auto const & elem : n){
        result += solve(elem - '0');
    }
    cout << result;
    return 0;
}