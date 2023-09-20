//
// Created by haram on 2023-09-20
//
// Problem-Solving #2631
#include <iostream>
#include <queue>
using namespace std;

int n;
int info[200];
int dp[200];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> info[i];

    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        dp[i] = 1;
        int maxVal = 0;
        for(int j = i - 1; j >= 0; --j){
            if(info[j] < info[i]){
                maxVal = max(maxVal, dp[j]);
            }
        }
        dp[i] = maxVal + 1;
    }

    int result = 0;
    for(int i = 0; i < n; ++i){
        result = max(result, dp[i]);
    }

    cout << n - result;

    return 0;
}