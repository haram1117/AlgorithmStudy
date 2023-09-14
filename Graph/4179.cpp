//
// Created by haram on 2023-09-13
//
// Problem-Solving #4179
#include <iostream>
#include <queue>
using namespace std;

int r, c;
char info[1000][1000];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pair<int, int> loc;

int price_fire[1000][1000];
queue<pair<int, int>> fires;
int result = 2000;

bool visited_jihoon[1000][1000];
void bfs_j(){
    visited_jihoon[loc.first][loc.second] = true;
    queue<pair<int, pair<int, int>>> q;
    q.emplace(0, loc);

    while(!q.empty()){
        int time = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(x * (x - r + 1) == 0 || y * (y - c + 1) == 0){
            result = min(result, time + 1);
        }

        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                if(visited_jihoon[nx][ny])
                    continue;
                if(info[nx][ny] == '#')
                    continue;
                if(price_fire[nx][ny] > time + 1)
                {
                    visited_jihoon[nx][ny] = true;
                    q.emplace(time + 1, make_pair(nx, ny));
                }
            }
        }
    }
}

bool visited_fire[1000][1000];
void bfs_f(int x, int y){
    queue<pair<int, pair<int, int>>> q;
    price_fire[x][y] = 0;
    q.emplace(0, make_pair(x, y));

    while(!q.empty()){
        int time = q.front().first;
        int _x = q.front().second.first;
        int _y = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = _x + dir[i][0];
            int ny = _y + dir[i][1];

            if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                if(info[nx][ny] == '#')
                    continue;
                if(price_fire[nx][ny] > time + 1){
                    price_fire[nx][ny] = time + 1;
                    q.emplace(time + 1, make_pair(nx, ny));
                }
            }
        }
    }
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;

    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j){
            cin >> info[i][j];
            if(info[i][j] == 'J')
                loc = {i, j};
            price_fire[i][j] = 2000;
        }

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(info[i][j] == 'F')
            {
                bfs_f(i, j);
            }
        }
    }

    bfs_j();

    if(result == 2000)
        cout << "IMPOSSIBLE";
    else
        cout << result;

    return 0;
}