//
// Created by haram on 2023-04-13.
//
#include <iostream>
using namespace std;

int n, m;

void solve(string str, int index, int num){
    str += to_string(index) + " ";
    if(num == 1){
        cout << str << '\n';
        return;
    }
    for(int i = index + 1; i <= n; ++i)
        solve(str, i, num - 1);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 1; i <= n - m + 1; ++i)
        solve("", i, m);


    return 0;
}