//
// Created by haram on 2023-09-15
//
// Problem-Solving #1027
#include <iostream>

using namespace std;

int n;
int info[50];
int result;
int solve(int idx, int flag){
    int count = 0;

    double tmp;
    for(int i = idx + flag; i >= 0 && i < n; i += flag){
        if(i == idx + flag){
            tmp = 1.0 * (info[idx] - info[i]) * (-1 * flag);
            count++;
            continue;
        }
        double d = 1.0 * (info[idx] - info[i]) / (idx - i);

        if(flag == -1){
            if(tmp > d){
                count++;
                tmp = d;
            }
        }
        else{
            if(tmp < d){
                count++;
                tmp = d;
            }
        }
    }
    return count;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> info[i];

    for(int i = 0; i < n; ++i){
        result = max(result, solve(i, -1) + solve(i, 1));
    }

    cout << result;

    return 0;
}