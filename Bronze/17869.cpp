//
// Created by haram on 2023-09-09
//
// Problem-Solving #17869
#include <iostream>
typedef unsigned long long ull;
using namespace std;
ull n;
int result;
void solve(ull num, int cnt){
    if(num == 1){
        result = cnt;
        return;
    }
    if(num % 2 == 0)
        solve(num / 2, cnt + 1);
    else
        solve(num + 1, cnt + 1);
}
int main(){
    cin >> n;
    solve(n, 0);
    cout << result;
    return 0;
}