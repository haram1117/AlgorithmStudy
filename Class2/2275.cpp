//
// Created by haram on 2023-03-16.
//
#include <iostream>
#include <vector>
using namespace std;
int info[15][15];
vector<pair<int, int>> input;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    int maxVal = 14;

    for(int i = 0; i < t; i++){
        int k, n;
        cin >> k >> n;
        maxVal = max(maxVal, k);
        input.push_back({k, n});
    }
    for(int j = 1; j <= 14; j++)
        info[0][j] = j;

    for(int i = 1; i <= maxVal; i++){
        for(int j = 1; j <= 14; j++){
            for(int k = 1; k <= j; k++)
                info[i][j] += info[i - 1][k];
        }
    }
    for(int i = 0; i < t; i++){
        cout << info[input[i].first][input[i].second] << '\n';
    }
    return 0;
}