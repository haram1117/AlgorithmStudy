//
// Created by haram on 2023-01-19.
//

#include <iostream>

using namespace std;

int input[1000];
int dp[1000];
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> input[i];

    int result = 0;
    for(int i = 0; i < n; i++){
        int tmp = 0;
        for(int j = 0; j < i; j++){
            if(input[i] <= input[j]){
                dp[j] = 0;
                continue;
            }
            int maxValue = 0;
            for(int k = 0; k < j; k++){
                if(input[k] < input[j]){
                    maxValue = max(maxValue, dp[k]);
                    tmp = max(tmp, maxValue);
                }
            }
            dp[j] = maxValue + 1;
            tmp = max(tmp, dp[j]);
        }
        dp[i] = tmp;
        for(int j = i + 1; j < n; j++){
            if(input[i] <= input[j]){
                dp[j] = 0;
                continue;
            }
            int maxValue = dp[i];
            for(int k = i + 1; k < j; k++){
                if(input[k] > input[j]){
                    maxValue = max(maxValue, dp[k]);
                    tmp = max(tmp, maxValue);
                }
            }
            dp[j] = maxValue + 1;
            tmp = max(tmp, dp[j]);
        }
//        for(int i = 0; i < n; i++){
//            cout << dp[i] << "\t";
//        }
//        cout << "\n";
        result = max(result, tmp);
    }
    cout << result+1 << endl;

    return 0;
}