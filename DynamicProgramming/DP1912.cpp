//
// Created by haram on 2023-01-02.
//

#include <iostream>
using namespace std;

int input[100000]; // input 배열 초기화
int dp[100000]; // dp 배열 초기화
int main(){

    // 입력
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        input[i] = temp;
    }

    // dp[0] 및 최종 결과 result 초기화
    dp[0] = input[0];
    int result = dp[0];

    // 각 element 마다 (전 dp 배열의 값 + input 값)과 (input값) 중
    // 더 큰 값을 dp[i]에 저장
    // 현재 result 보다 해당 값이 더 크면 result 업데이트
    for(int i = 1; i < N; i++){
        dp[i] = max(dp[i - 1] + input[i], input[i]);
        result = max(result, dp[i]);
    }

    // 출력
    cout << result << endl;

    return 0;
}