//
// Created by haram on 2023-01-08.
//

#include <iostream>

using namespace std;

int input[300];
int dp[300];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    dp[0] = input[0];
    dp[1] = dp[0] + input[1];
    dp[2] = max(dp[0] + input[2], input[1] + input[2]);
    for(int i = 2; i < n; i++){
        int temp1 = dp[i - 2] + input[i];
        int temp2;
        if(i < 3)
            temp2 = input[i - 1] + input[i];
        else
            temp2 = dp[i - 3] + input[i - 1] + input[i];

        dp[i] = max(temp1, temp2);
    }

    cout << dp[n - 1] << endl;
    return 0;
}