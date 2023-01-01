//
// Created by haram on 2022-12-30.
//

#include <iostream>
using namespace std;

int dp[100000];

int main(){

    int N;
    cin >> N;

    dp[1] = 1;
    for(int i = 2; i <= N; i++){
        dp[i] = i;
    }

    for(int i = 2; i <= N; i++){
        int temp = 2;
        while(true){
            if(i < temp * temp)
                break;
            else if(i == temp * temp)
                dp[i] = 1;
            dp[i] = min(dp[i], dp[i - temp * temp] + 1);
            temp++;
        }
    }
    cout << dp[N];
    return 0;
}