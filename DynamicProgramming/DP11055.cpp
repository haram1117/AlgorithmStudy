//
// Created by haram on 2023-01-20.
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

    dp[0] = input[0];
    int result = dp[0];
    for(int i = 1; i < n; i++){
        int maxVal = 0;
        for(int j = 0; j < i; j++){
            if(input[i] > input[j]){
                maxVal = max(maxVal, dp[j]);
            }
        }
        dp[i] = input[i] + maxVal;
        result = max(result, dp[i]);
    }

    cout << result << endl;
    return 0;
}


// 1    100 2   50  60  3   5   6   7   8
// 1    100 3   53  113 6   11  17  24  32