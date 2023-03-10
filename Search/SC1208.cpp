//
// Created by haram on 2023-03-10.
//
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, s;
int input[40];
long long result;
map<int, int> sumMap;

void left(int idx, int sum){
    if(idx == n / 2){
        result += sumMap[s - sum];
        return;
    }
    left(idx + 1, sum); // input[idx] 포함 안하고 다음으로 넘어감
    left(idx + 1, sum + input[idx]); // input[idx] 포함 후 다음으로 넘어감
}

void right(int idx, int sum){
    if(idx == n){
        sumMap[sum]++;
        return;
    }
    right(idx + 1, sum);
    right(idx + 1, sum + input[idx]);
}

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    right(n / 2, 0);
    left(0, 0);

    if(s == 0)
        cout << result - 1;
    else
        cout << result;
    return 0;
}