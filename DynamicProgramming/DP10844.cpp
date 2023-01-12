//
// Created by haram on 2023-01-12.
//

#include <iostream>

using namespace std;

int dp[100][12];
int main(){
    int n;
    cin >> n;

    for(int i = 2; i < 11; i++)
        dp[0][i] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 1; j < 11; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    int result = 0;
    for(int i = 1; i < 11; i++){
        result += dp[n - 1][i];
        result %= 1000000000;
    }

    cout << result;

    return 0;
}