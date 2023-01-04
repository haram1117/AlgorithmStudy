//
// Created by haram on 2023-01-04.
//
#include <iostream>
using namespace std;

int dp[30];
int main(){
    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = 3;

    // 각 element 당 dp 값 채우기
    for(int i = 2; i < N; i++){
        if(i % 2 == 0) // N = 1, N = 3, N = 5 등 N이 홀수일 때 dp값 0 (index 는 짝수)
            dp[i] = 0;
        else{
            dp[i] = dp[i - 2] * 3;
            int temp = 0;
            for(int j = i - 4; j > 0; j -= 2){
                temp += dp[j];
            }
            temp += 1;
            dp[i] += temp * 2;
        }
    }

    cout << dp[N-1] << endl;
    return 0;
}