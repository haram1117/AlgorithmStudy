//
// Created by haram on 2023-09-12
//
// Problem-Solving #19602
#include <iostream>

using namespace std;
int s, m, l;
int main(){
    cin >> s >> m >> l;
    if(s + 2 * m + 3 * l >= 10)
        cout << "happy";
    else
        cout << "sad";
    return 0;
}