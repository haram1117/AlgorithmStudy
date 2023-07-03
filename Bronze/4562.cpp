//
// Created by haram on 2023-06-29.
//
#include <iostream>

using namespace std;
int n;
int main(){
    cin >> n;
    int a, b;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        if(a >= b)
            cout << "MMM BRAINS\n";
        else
            cout << "NO BRAINS\n";
    }
    return 0;
}