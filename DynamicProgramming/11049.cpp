//
// Created by haram on 2023-07-25
//
// Problem-Solving #11049

#include <iostream>
#define MAX 2147483647
using namespace std;

pair<int, int> input[501];
int dp[501][501];
int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> input[i].first >> input[i].second;
    }

    for(int i = 1; i < n; ++i){
        for(int j = 1; j + i <= n; ++j){
            dp[j][j + i] = MAX;
            for(int k = j; k < j + i; ++k){
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i]
                + input[j].first * input[k].second * input[j + i].second);
            }
        }
    }

    cout << dp[1][n];

    return 0;
}