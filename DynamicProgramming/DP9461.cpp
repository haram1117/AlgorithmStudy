//
// Created by haram on 2023-01-10.
//

#include <iostream>

using namespace std;

long long dp[100];
int main(){
    int t;
    cin >> t;
    int* input = new int[t];
    int max = 0;
    for(int i = 0; i < t; i++){
        cin >> input[i];
        if (input[i] > max)
            max = input[i];
    }
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = dp[4] = 2;
    for(int i = 5; i < max; i++){
        dp[i] = dp[i - 5] + dp[i - 1];
    }
    for(int i = 0; i < t; i++){
        cout << dp[input[i] - 1] << "\n";
    }
    return 0;
}