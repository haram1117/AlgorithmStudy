//
// Created by haram on 2023-02-24.
//
#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001];
bool visited[1001][1001];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
queue<pair<int, int>> queue1;

int bfs(){
    int count = 0;
    int num = queue1.size();
    while(!queue1.empty()){
        for(int k = 0; k < num; k++){
            int x = queue1.front().first;
            int y = queue1.front().second;
            queue1.pop();

            for(auto & i : dir){
                int nx = x + i[0];
                int ny = y + i[1];
                if(nx >= 1 && ny >= 1 && nx <= m && ny <= n){
                    if(!visited[nx][ny] && graph[nx][ny] == 0){
                        queue1.emplace(nx, ny);
                        graph[nx][ny] = 1;
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        num = queue1.size();
        count++;
    }
    count--;
    return count;
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 1){
                queue1.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }

    int result = bfs();
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == 0){
                cout << -1;
                return 0;
            }
        }
    }
    cout << result;
    return 0;
}