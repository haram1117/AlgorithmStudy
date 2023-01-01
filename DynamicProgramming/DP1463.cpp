//
// Created by haram on 2022-12-30.
//

#include <iostream>
using namespace std;

int dp[1000000]; // dp 배열 초기화
int main(){

    // 입력
    int N;
    cin >> N;

    // 1은 0번을 거쳐 1에 도달할 수 있다.
    dp[1] = 0;

    // 각 숫자마다 연산을 하는 횟수 구하기
    for(int i = 2; i <= N; i++){

        // i를 구하기 위해 dp[i - 1]에서 1을 더한다.
        dp[i] = dp[i - 1] + 1;

        // 2로 나누어 떨어질 때
        if (i % 2 == 0){
            // 앞서 구한 dp[i - 1] + 1과 dp[i / 2] + 1을 비교하여 min값을 dp[i]에 저장한다.
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        // 3으로 나누어 떨어질 때
        if (i % 3 == 0){
            // 앞서 구한 dp[i - 1] + 1과 dp[i / 3] + 1을 비교하여 min값을 dp[i]에 저장한다.
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    // 출력
    cout << dp[N];

    return 0;
}