//
// Created by haram on 2023-01-24.
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

    dp[0] = 1;
    for(int i = 1; i < n; i++){
        int maxVal = 0;
        for(int j = 0; j < i; j++){
            if(input[i] < input[j]){
                maxVal = max(maxVal, dp[j]);
            }
        }
        dp[i] = maxVal + 1;
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        result = max(result, dp[i]);
    }

    cout << result << endl;
    return 0;
}