//
// Created by haram on 2023-01-05.
//

#include <iostream>
using namespace std;

int input[10000];
int dp[10000];
int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    dp[0] = input[0];
    int check = 0;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1] + input[i];
        check++;
        if(check >= 2){
            int temp1 = input[i - 1] + input[i];
            if(i >= 3)
                temp1 = input[i - 1] + input[i] + dp[i - 3]; // input[i] 선택 + input[i-1] 선택
            int temp2 = input[i] + dp[i - 2]; // input[i] 선택 + input[i-1] 선택 x
            int temp3 = dp[i - 1]; // input[i] 선택 x
            dp[i] = max(max(temp1, temp2), temp3);
            if(dp[i] == temp1)
                check = 2;
            else if(dp[i] == temp2)
                check = 1;
            else
                check = 0;
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}