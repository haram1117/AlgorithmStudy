//
// Created by haram on 2023-07-18
//
// Problem-Solving #11066

#include <iostream>
#define MAX 987654321
using namespace std;

int dp[501][501];
int cost[501];
int sum[501];
int t;
int n;

void solve(){
    for(int i = 1; i < n; ++i){
        for(int j = 1; j + i <= n; ++j){
            dp[j][j + i] = MAX;

            for(int k = j; k < j + i; ++k){
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1]);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int tc = 0; tc < t; ++tc){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }
        solve();

        cout << dp[1][n] << '\n';
    }

    return 0;
}