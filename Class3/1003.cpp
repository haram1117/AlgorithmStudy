//
// Created by haram on 2023-03-17.
//
#include <iostream>
#include <queue>
using namespace std;


int t;
int dp[40][2];
queue<int> input;
int main(){
    cin >> t;
    int maxVal = 0;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        input.push(n);
        maxVal = max(n, maxVal);
    }
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for(int i = 2; i <= maxVal; i++){
        dp[i][0] = dp[i - 2][0] + dp[i - 1][0];
        dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
    }
    while(!input.empty()){
        cout << dp[input.front()][0] << " " << dp[input.front()][1] << '\n';
        input.pop();
    }
    return 0;
}