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
            for(int k = 0; k < 3; ++k)
            {
                int ni = i + dir[k][0];
                int nj = j + dir[k][1];
                if(nj < 0 || nj >= m)
                    continue;
                for(int s = 0; s < 3; ++s){
                    if(s == k)
                        continue;
                    minVal = min(minVal, info[ni][nj][s]);
                }
                info[i][j][k] += minVal;
            }
        }
    }

    int result = 600;
    for(int i = 0; i < m; ++i)
        for(int k = 0; k < 3; ++k)
            result = min(result, info[n - 1][i][k]);
    cout << result;

    return 0;
}