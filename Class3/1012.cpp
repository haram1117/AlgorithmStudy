//
// Created by haram on 2023-03-17.
//
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int t;
int input[50][50];
bool visited[50][50];
int n, m, k;
int groupNum = 1;
int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void bfs(int x, int y){
    groupNum++;

    queue<pair<int, int>> queue1;
    queue1.emplace(x, y);
    visited[x][y] = true;

    while(!queue1.empty()){
        int _x = queue1.front().first;
        int _y = queue1.front().second;

        input[_x][_y] = groupNum;

        queue1.pop();

        for(int i = 0; i < 4; i++){
            int dx = _x + dir[i][0];
            int dy = _y + dir[i][1];
            if(dx >= 0 && dx < m && dy >= 0 && dy < n){
                if(!visited[dx][dy] && input[dx][dy] == 1){
                    queue1.emplace(dx, dy);
                    visited[dx][dy] = 1;
                }
            }
        }
    }

}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> m >> n >> k;
        for(int j = 0; j < k; j++){
            int x, y;
            cin >> x >> y;
            input[x][y] = 1;
        }
        for(int j = 0; j < m; j++){
            for(int h = 0; h < n; h++){
                if(!visited[j][h] && input[j][h] == 1)
                    bfs(j, h);
            }
        }
        cout << groupNum - 1 << '\n';
        groupNum = 1;
        memset(input, 0, sizeof(input));
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}