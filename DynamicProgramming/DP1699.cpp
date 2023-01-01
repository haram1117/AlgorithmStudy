//
// Created by haram on 2022-12-30.
//

#include <iostream>
using namespace std;

int dp[100000]; // dp 배열 초기화

int main(){

    // 입력
    int N;
    cin >> N;

    // 각 수를 1^2만으로 더했을 때의 항의 개수를 배열에 저장
    for(int i = 1; i <= N; i++){
        dp[i] = i;
    }


    for(int i = 2; i <= N; i++){

        // i보다 작은 제곱수부터 최소 항의 개수 계산
        int temp = 2;
        while(true){
            // 제곱수가 i보다 크면 반복 종료
            if(i < temp * temp)
                break;
            else if(i == temp * temp) // i가 제곱수가 되면 dp[i] = 1
                dp[i] = 1;
            // dp[i]에 현재 항의 개수와 i - temp * temp의 항의 개수 + 1 중 min 값 저장
            dp[i] = min(dp[i], dp[i - temp * temp] + 1);
            temp++;
        }
    }
    // 출력
    cout << dp[N];
    return 0;
}