//
// Created by haram on 2023-01-07.
//

#include <iostream>

using namespace std;

long long dp[201];
int main(){
    int n, k;
    cin >> n >> k;

    // 1
    if(k == 1){
        cout << 1;
        return 0;
    }

    // 2
    for(int i = 0; i < n + 1; i++){
        dp[i] = 1;
    }

    // 3 ~ k
    for(int i = 0; i < k - 2; i++){
        for(int j = n - 1; j >= 0; j--){
            dp[j] = dp[j] % 1000000000 + dp[j + 1] % 1000000000;
        }
    }

    long long result = 0;
    for(int i = 0; i < n + 1; i++){
        result += dp[i] % 1000000000;
    }

    cout << result % 1000000000;

    return 0;
}