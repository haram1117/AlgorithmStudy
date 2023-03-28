//
// Created by haram on 2023-03-28.
//
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

int n;
int answer = 50001;
int cnts[50001];

void solve(int num, int cnt){
    cnts[num] = cnt;
    int largest = (int)sqrt(num);
    if(num / (float)largest == largest){
        answer = min(answer, cnt);
        return;
    }
    for(int i = largest; i * i >= 1; i--){
        if(cnts[num - i * i] > cnt + 1)
            solve(num - i * i, cnt + 1);
    }
}

int main(){
    cin >> n;
    memset(cnts, 50001, n * sizeof(int));
    solve(n, 1);

    cout << answer;

    return 0;
}