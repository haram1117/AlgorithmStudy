//
// Created by haram on 2023-01-11.
//

#include <iostream>

using namespace std;

int input[2][100000];
int dp[2][100000];
int main(){
    int t, n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    int* results = new int[t];
    for(int k = 0; k < t; k++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> input[0][i];
        }
        for(int i = 0; i < n; i++){
            cin >> input[1][i];
        }

        dp[0][0] = input[0][0];
        dp[1][0] = input[1][0];
        dp[0][1] = input[0][1] + dp[1][0];
        dp[1][1] = input[1][1] + dp[0][0];

        for(int i = 1; i < n; i++){
            dp[0][i] = input[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = input[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }
        results[k] = max(dp[0][n - 1], dp[1][n - 1]);
    }

    for(int i = 0; i < t; i++){
        cout << results[i] << endl;
    }

    delete[] results;
    return 0;
}