//
// Created by haram on 2023-09-08
//
// Problem-Solving #4485
#include <iostream>
#include <queue>
using namespace std;
int map[125][125];
int visited[125][125];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int t = 1, n;

void dijkstra(){
    visited[0][0] = map[0][0];
    queue<pair<int, int>> q;
    q.emplace(0, 0);

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int price = visited[x][y];
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(visited[nx][ny] > price + map[nx][ny]){
                    visited[nx][ny] = price + map[nx][ny];
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                visited[i][j] = 987654321;
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> map[i][j];
            }
        }
        dijkstra();

        cout << "Problem " << t << ": " << visited[n - 1][n - 1] << '\n';
        t++;
    }
    return 0;
}