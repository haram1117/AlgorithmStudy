//
// Created by haram on 2023-03-21.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int input[100][100][100];
int visited[100][100][100];
int dir[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
int n, m, h;
int result = 1;
queue<vector<int>> q;
void bfs(){
    while(!q.empty()){
        int _x = q.front()[1];
        int _y = q.front()[2];
        int _z = q.front()[0];
        q.pop();

        for(int i = 0; i < 6; i++){
            int dx = _x + dir[i][1];
            int dy = _y + dir[i][2];
            int dz = _z + dir[i][0];
            if(dx >= 0 && dx <= n - 1 && dy >= 0 && dy <= m - 1 && dz >= 0 && dz <= h - 1){
                if(!visited[dz][dx][dy] && input[dz][dx][dy] == 0){
                    q.push({dz, dx, dy});
                    input[dz][dx][dy] = input[_z][_x][_y] + 1;
                    result = input[dz][dx][dy];
                    visited[dz][dx][dy] = true;
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin >> input[i][j][k];
            }
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(input[i][j][k] == 1){
                    q.push({i, j, k});
                    visited[i][j][k] = true;
                }
            }
        }
    }
    bfs();

    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(input[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << result - 1;

    return 0;
}