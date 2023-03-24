//
// Created by haram on 2023-03-24.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
bool visited[100][100];
char input1[100][100];
char input2[100][100];

int n;
int result = 0;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int _x, int _y){
    queue<pair<int, int>> q;
    q.emplace(_x, _y);
    visited[_x][_y] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(!visited[nx][ny] && input1[x][y] == input1[nx][ny]){
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    result++;
}

void bfs2(int _x, int _y){
    queue<pair<int, int>> q;
    q.emplace(_x, _y);
    visited[_x][_y] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(!visited[nx][ny] && input2[x][y] == input2[nx][ny]){
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }
    result++;
}



int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> input1[i][j];
            if(input1[i][j] == 'G')
                input2[i][j] = 'R';
            else
                input2[i][j] = input1[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                bfs(i, j);
            }
        }
    }
    cout << result << " ";
    memset(visited, false, sizeof(visited));
    result = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                bfs2(i, j);
            }
        }
    }
    cout << result;

    return 0;
}