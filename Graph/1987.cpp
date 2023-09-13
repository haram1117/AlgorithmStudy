//
// Created by haram on 2023-09-13
//
// Problem-Solving #1987
#include <iostream>

using namespace std;
int r, c;
char info[20][20];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int result;

void dfs(int x, int y, bool ch_visited[], bool visited[][20], int count){
    result = max(result, count);
    visited[x][y] = true;
    ch_visited[info[x][y] - 'A'] = true;

    for(int i = 0; i < 4; ++i){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(nx >= 0 && nx < r && ny >= 0 && ny < c){
            if(visited[nx][ny])
                continue;
            if(ch_visited[info[nx][ny] - 'A'])
                continue;
            dfs(nx, ny, ch_visited, visited, count + 1);
            visited[nx][ny] = false;
            ch_visited[info[nx][ny] - 'A'] = false;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j)
            cin >> info[i][j];
    }

    bool ch_visited[26];
    bool visited[20][20];

    for(int i = 0; i < 26; ++i)
        ch_visited[i] = false;
    for(int i = 0; i < 20; ++i)
        for(int j = 0; j < 20; ++j)
            visited[i][j] = false;

    dfs(0, 0, ch_visited, visited, 1);

    cout << result;
    return 0;
}