//
// Created by haram on 2023-01-22.
//
#include <iostream>
using namespace std;

long long dp[2][10];
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < 10; i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0){
                dp[i % 2][j] = 1;
                continue;
            }
            dp[i % 2][j] = dp[(1 ^ (i % 2))][j] % 10007 + dp[i % 2][j - 1] % 10007;
        }
    }
    long long result = 0;
    for(int i = 0; i < 10; i++) {
        result += dp[(1 ^ (n % 2))][i] % 10007;
    }
    cout << result % 10007 << endl;

    return 0;
}

/* _
 * 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
 *
 * _ _
 * 0 _ -> 10
 * 1 _ -> 9
 * 2 _ -> 8
 * 3 _ -> 7
 * ...
 *
 * _ _ _
 *
 * */