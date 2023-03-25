//
// Created by haram on 2023-03-25.
//
#include <iostream>
#include <cstring>

using namespace std;

int input[500][500];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;
int result;
bool visited[500][500];

void dfs(int x, int y, int cnt, int sum){
    cnt += 1;
    visited[x][y] = true;
    sum += input[x][y];
    if(cnt >= 4)
        result = max(result, sum);
    else{
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1){
                if(!visited[nx][ny]){
                    dfs(nx, ny, cnt, sum);
                    visited[nx][ny] = false;
                }
            }
        }
    }
}

void check(int i, int j){
    pair<int, int> array[4][4] = {{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
                                  {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
                                  {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
                                  {{0, 0}, {1, 0}, {2, 0}, {1, -1}}
                                  };
    for(int k = 0; k < 4; k++){
        int sum = 0;
        for(int p = 0; p < 4; p++){
            int nx = i + array[k][p].first;
            int ny = j + array[k][p].second;
            if(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)
                sum += input[nx][ny];
            else
                break;
        }
        result = max(result, sum);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> input[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dfs(i, j, 0, 0);
            check(i, j);
            memset(visited, false, sizeof(visited));
        }
    }
    cout << result;

    return 0;
}