//
// Created by haram on 2023-03-29.
//
#include <iostream>

using namespace std;
int n;
int input[1000][3];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }

    for(int i = 1; i < n; i++){
        input[i][0] = input[i][0] + min(input[i - 1][1], input[i - 1][2]);
        input[i][1] = input[i][1] + min(input[i - 1][0], input[i - 1][2]);
        input[i][2] = input[i][2] + min(input[i - 1][0], input[i - 1][1]);
    }

    int result = min(input[n - 1][0], min(input[n - 1][1], input[n - 1][2]));
    cout << result;
    return 0;
}