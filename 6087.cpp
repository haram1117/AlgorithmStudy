//
// Created by haram on 2023-07-17
//
// Problem-Solving #6087

#include <iostream>
#include <queue>
using namespace std;

int w, h;
char map[100][100];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> c;
bool visited[100][100];
int price[100][100];

void bfs(){
    queue<pair<int, int>> q;
    visited[c[0].first][c[0].second] = true;
    price[c[0].first][c[0].second] = 0;
    q.emplace(c[0].first, c[0].second);

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            while(nx >= 0 && nx < h && ny >= 0 && ny < w){
                if(map[nx][ny] == '*')  break;
                if(!visited[nx][ny]){
                    visited[nx][ny] = true;
                    price[nx][ny] = price[x][y] + 1;
                    q.emplace(nx, ny);
                }
                nx += dir[i][0];
                ny += dir[i][1];
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> w >> h;
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j){
            cin >> map[i][j];
            visited[i][j] = false;
            price[i][j] = 987654321;
            if(map[i][j] == 'C'){
                c.emplace_back(i, j);
            }
        }

    bfs();

    cout << price[c[1].first][c[1].second] - 1;

    return 0;
}