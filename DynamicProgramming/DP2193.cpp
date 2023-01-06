//
// Created by haram on 2023-01-06.
//

#include <iostream>
using namespace std;

long long dp[90];
int main(){
    int n;
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n - 1] << endl;

    return 0;
}