//
// Created by haram on 2023-01-09.
//

#include <iostream>
using namespace std;

int dp[10];
int main(){
    int n;
    cin >> n;

    int* input = new int[n];

    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> input[i];
        if(input[i] > max)
            max = input[i];
    }

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for(int i = 3; i < max; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    for(int i = 0; i < n; i++)
    {
        cout << dp[input[i] - 1] << endl;
    }

    delete[] input;
    return 0;
}