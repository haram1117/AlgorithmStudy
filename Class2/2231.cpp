//
// Created by haram on 2023-03-16.
//
#include <iostream>

using namespace std;
int n;
int result;
void solve(){
    for(int i = 1; i < n; i++){
        int sum = i;
        string str = to_string(i);
        for(auto elem : str){
            sum += elem - '0';
        }
        if(sum == n){
            result = i;
            return;
        }
    }
}
int main(){
    cin >> n;
    solve();
    cout << result;
    return 0;
}