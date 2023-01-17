//
// Created by haram on 2023-01-17.
//

#include <iostream>
using namespace std;

int input[1000];
int dp[1000];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    for(int i = 0; i < n; i++){
        dp[i] = input[i];
        for(int j = 0; j < float(i) / 2; j++){
            dp[i] = max(dp[i], dp[j] + dp[i - j - 1]);
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}