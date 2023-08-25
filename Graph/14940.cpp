//
// Created by haram on 2023-08-25
//
// Problem-Solving #14940
#include <iostream>
#include <queue>

using namespace std;
int n, m;
int map[1000][1000];
bool visited[1000][1000];
pair<int, int> start;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(){
    queue<pair<int, int>> q;

    q.emplace(start);
    map[start.first][start.second] = 0;
    visited[start.first][start.second] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(visited[nx][ny])
                continue;
            if(map[nx][ny] == 0)
                continue;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                map[nx][ny] = map[x][y] + 1;
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> map[i][j];
            if(map[i][j] == 2)
                start = {i, j};
        }
    }

    bfs();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] && map[i][j] != 0)
                cout << -1 << " ";
            else
                cout << map[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}