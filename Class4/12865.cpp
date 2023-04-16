//
// Created by haram on 2023-04-14.
//
#include <iostream>
using namespace std;

int n, k;
int table[101][100001];
int weight[101];
int value[101];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 1; i <= n; ++i){
        cin >> weight[i] >> value[i];
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            if(j - weight[i] >= 0)
                table[i][j] = max(table[i - 1][j], table[i - 1][j - weight[i]] + value[i]);
            else
                table[i][j] = table[i - 1][j];
        }
    }
    cout << table[n][k];
    return 0;
}