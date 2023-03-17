//
// Created by haram on 2023-03-16.
//
#include <iostream>

using namespace std;
int n, m, b;
int input[500][500];
int maxVal = 0;
int minVal = 256;
int resultTime = 10000000000;
int resultHeight;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> b;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> input[i][j];
            maxVal = max(maxVal, input[i][j]);
            minVal = min(minVal, input[i][j]);
        }
    }
    for(int k = minVal; k <= maxVal; k++){
        int need = 0;
        int remove = 0;
        int get = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(input[i][j] > k){
                    remove += input[i][j] - k;
                    get += input[i][j] - k;
                }
                else if(input[i][j] < k)
                    need += k - input[i][j];
            }
        }
        if(need > b + get)
            continue;
        if(resultTime > 2 * remove + need){
            resultTime = 2 * remove + need;
            resultHeight = k;
        }
        else if(resultTime == 2 * remove + need){
            resultHeight = max(resultHeight, k);
        }
    }

    cout << resultTime << " " << resultHeight;

    return 0;
}