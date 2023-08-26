//
// Created by haram on 2023-08-26
//
// Problem-Solving #15989
#include <iostream>
#include <queue>
using namespace std;
pair<int, int> dp[10001];
int t;
queue<int> tc;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    int M = 0;
    while(t--){
        int n;
        cin >> n;
        M = max(M, n);
        tc.emplace(n);
    }

    dp[1] = {0, 1};
    dp[2] = {1, 1};
    dp[3] = {1, 2};
    dp[4] = {1, 3};
    dp[5] = {1, 4};

    for(int i = 6; i <= M; ++i){
        dp[i].first = dp[i - 3].first + dp[i - 2].first - dp[i - 5].first;
        dp[i].second = dp[i - 1].first + dp[i - 1].second;
    }

    while(!tc.empty()){
        cout << dp[tc.front()].first + dp[tc.front()].second << '\n';
        tc.pop();
    }
    return 0;
}