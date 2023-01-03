//
// Created by haram on 2023-01-03.
//

#include <iostream>
#include <string>
using namespace std;

int input[5000];
int dp[5000];

int main(){
    // 입력
    string inputStr;
    cin >> inputStr;
    int num = inputStr.size();
    int newNum = 0;
    for(int i, j = 0; i < num; i++, j++){
        input[j] = inputStr[i] - '0'; // char to int

        // 방금 들어온 input이 0이면,
        // 앞 숫자에 10 곱해서 앞 인덱스에 집어넣기
        if(input[j] == 0){
            input[j - 1] = input[j - 1] * 10;
            j--; // input index 감소

            // 앞 숫자에 10 곱한 수가 26보다 크거나 0보다 작거나 같으면
            // 해석할 수 없는 암호로 0 출력 후 종료
            if(input[j] > 26 || input[j] <= 0){
                cout << 0 << endl;
                return 0;
            }
        }
        // input 배열 size  newNum으로 재정의
        newNum = j + 1;
    }

    // dp[0]으로 만들 수 있는 조합 1개
    dp[0] = 1;

    // 각 elem 돌면서 dp table 업데이트
    for(int i = 1; i < newNum; i++){
        if(input[i] + 10 * input[i - 1] <= 26 && input[i] < 10){
            if(i == 1)
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        else
            dp[i] = dp[i - 1];

        dp[i] %= 1000000;
    }

    // 출력
    cout << dp[newNum - 1] << endl;
    return 0;
}