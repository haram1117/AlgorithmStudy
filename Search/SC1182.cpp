//
// Created by haram on 2023-03-10.
//
#include <iostream>
using namespace std;

int n, s;
int input[20];
int result;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    // 부분 집합의 개수 : 2 ^ n
    for(int b = 1; b < (1<<n); b++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(b & (1 << i))
                sum += input[i];
        }
        if(sum == s)
            result++;
    }

    cout << result;

    return 0;
}