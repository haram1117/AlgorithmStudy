//
// Created by haram on 2023-04-12.
//
#include <iostream>
using namespace std;

int n;
int result;
int table[15];

bool promising(int x){
    for(int i = 0; i < x; i++){
        if(table[x] == table[i] || x - i == abs(table[x] - table[i]))
            return false;
    }
    return true;
}

void solve(int x){
    if(x == n){
        result++;
        return;
    }

    for(int i = 0; i < n; i++){
        table[x] = i;
        if(promising(x))
            solve(x + 1);
    }
}

int main(){
    cin >> n;
    solve(0);
    cout << result;
    return 0;
}