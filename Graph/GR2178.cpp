//
// Created by haram on 2023-02-20.
//
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int input[101][101];
bool visited[101][101];

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(){
    queue<pair<int, int>> queue1;

    visited[1][1] = true;
    queue1.emplace(1, 1);

    while(!queue1.empty()){
        int x = queue1.front().first;
        int y = queue1.front().second;
        queue1.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx >= 1 && dy >= 1 && dx <= n && dy <= m){
                if(!visited[dx][dy] && input[dx][dy]){
                    queue1.emplace(dx, dy);
                    visited[dx][dy] = true;
                    input[dx][dy] = input[x][y] + 1;
                }
            }
        }
    }
    cout << input[n][m];
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char tmp;
            cin >> tmp;
            input[i][j] = tmp - '0';
        }
    }

    bfs();


    return 0;
}