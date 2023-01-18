//
// Created by haram on 2023-01-18.
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
    int result = 1;
    for(int i = 1; i < n; i++){
        int temp = 0;
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(input[i] > input[j]){
                if(temp < dp[j]){
                    temp = dp[j];
                    dp[i] = temp + 1;
                }
            }
        }
        if(result < dp[i])
            result = dp[i];
    }

    cout << result << endl;

    return 0;
}