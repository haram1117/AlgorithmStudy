//
// Created by haram on 2023-04-09.
//
#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool input[1000][1000];
bool visited[1000][1000][2];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int result = -1;

void bfs(){
    visited[0][0][0] = true;
    queue<pair<pair<int, int>, pair<int, int>>> q;

    q.push({{0, 0}, {1, 0}});

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second.first;
        int check = q.front().second.second;
        q.pop();
        if(x == n - 1 && y == m - 1){
            result = dist;
            return;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny][check]){
                if(!input[nx][ny]){ // 벽 없는 곳
                    // 부순 적 없음
                    // 한번 부숨 (더이상 못부숨)
                    visited[nx][ny][check] = true;
                    q.push({{nx, ny}, {dist + 1, check}});
                }
                else{ // 벽 있는 곳
                    if(check == 0){ // 부순 적 없음
                        visited[nx][ny][check] = true;
                        q.push({{nx, ny}, {dist + 1, 1}});
                    }
                    // 부순 적이 있는데 벽 있는 곳은 못감
                }
            }
        }
    }
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            if(tmp == '0')
                input[i][j] = false;
            else
                input[i][j] = true;
        }
    }
    bfs();
    cout << result;
    return 0;
}