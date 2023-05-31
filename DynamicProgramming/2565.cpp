//
// Created by haram on 2023-05-31.
//
#include <iostream>
#include <queue>
using namespace std;
int n;
int info[101];
int dp[101];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(int i = 0; i < n; ++i){
        int s, e;
        cin >> s >> e;
        pq.emplace(s, e);
    }

    for(int i = 0; i < n; ++i){
        info[i] = pq.top().second;
        pq.pop();
    }

    int result = 0;
    for(int i = 0; i < n; ++i){
        dp[i] = 1;
        int tmp = 0;
        for(int j = 0; j < i; ++j){
            if(info[j] < info[i]){
                tmp = max(tmp, dp[j]);
            }
        }
        dp[i] = max(dp[i], tmp + 1);
        if(result < dp[i])
            result = dp[i];
    }

    cout << n - result;

    return 0;
}