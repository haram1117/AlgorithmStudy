//
// Created by haram on 2023-08-12
//
// Problem-Solving #17484
#include <iostream>

using namespace std;

int n, m;
int info[6][6][3];
int dir[3][2] = {{-1, 0}, {-1, -1}, {-1, 1}};
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            int tmp;
            cin >> tmp;
            info[i][j][0] = tmp;
            info[i][j][1] = tmp;
            info[i][j][2] = tmp;
        }

    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            int minVal = 600;
            if(j + 1 < m){
                minVal = min(minVal, info[i - 1][j + 1][1]);
                minVal = min(minVal, info[i - 1][j + 1][2]);
                info[i][j][0] += minVal;
            }
            else
                info[i][j][0] = 600;

            minVal = 600;
            minVal = min(minVal, info[i - 1][j][0]);
            minVal = min(minVal, info[i - 1][j][2]);
            info[i][j][1] += minVal;

            if(j - 1 >= 0){
                minVal = 600;
                minVal = min(minVal, info[i - 1][j - 1][0]);
                minVal = min(minVal, info[i - 1][j - 1][1]);
                info[i][j][2] += minVal;
            }
            else
                info[i][j][2] = 600;
        }
    }

    int result = 600;
    for(int i = 0; i < m; ++i)
        for(int k = 0; k < 3; ++k)
            result = min(result, info[n - 1][i][k]);
    cout << result;

    return 0;
}