//
// Created by haram on 2023-02-21.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int graph[51][51];
bool visited[51][51];
int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int groupIndex = 1;

int w, h;

void bfs(int x, int y){
    queue<pair<int, int>> queue1;
    queue1.emplace(x, y);
    visited[x][y] = true;
    graph[x][y] = groupIndex;

    while(!queue1.empty()){
        x = queue1.front().first;
        y = queue1.front().second;
        queue1.pop();

        for(auto & i : dir){
            int nx = x + i[0];
            int ny = y + i[1];
                if(nx >= 1 && ny >= 1 && nx <= h && ny <= w){
                if(!visited[nx][ny] && graph[nx][ny] == 1){
                    visited[nx][ny] = true;
                    graph[nx][ny] = groupIndex;
                    queue1.emplace(nx, ny);
                }
            }
        }
    }
}

int main(){
    while(true){
        cin >> w >> h;
        if(!w && !h)
            break;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> graph[i][j];
            }
        }
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                if(graph[i][j] == 1){
                    groupIndex++;
                    bfs(i, j);
                    i = 0; j = 0;
                }
            }
        }
        if(groupIndex != 0)
            groupIndex--;
        cout << groupIndex << "\n";
        groupIndex = 1;
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}