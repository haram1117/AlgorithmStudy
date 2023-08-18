//
// Created by haram on 2023-08-18.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, l, r;
int cntInfo[50][50];
bool openInfo[50][50][4];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[50][50];

void setOpenInfo(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < 4; ++k){
                int ni = i + dir[k][0];
                int nj = j + dir[k][1];
                if(ni >= 0 && ni < n && nj >= 0 && nj < n){
                    int tmp = abs(cntInfo[i][j] - cntInfo[ni][nj]);
                    if(tmp >= l && tmp <= r)
                        openInfo[i][j][k] = true;
                }
            }
        }
    }
}

bool bfs(int si, int sj){
    queue<pair<int, int>> changeQ;
    visited[si][sj] = true;
    queue<pair<int, int>> q;
    q.emplace(si, sj);
    int sum = 0;
    int cnt = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        changeQ.emplace(x, y);
        sum += cntInfo[x][y];
        cnt ++;

        q.pop();

        for(int i = 0; i < 4; ++i){
            if(!openInfo[x][y][i])
                continue;
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(!visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    if(changeQ.size() == 1)
        return false;

    int value = sum / cnt;
    while(!changeQ.empty()){
        int x = changeQ.front().first;
        int y = changeQ.front().second;
        changeQ.pop();
        cntInfo[x][y] = value;
    }
    return true;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> l >> r;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> cntInfo[i][j];
        }
    }

    int result = 0;
    while(result <= 2000){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < 4; ++k)
                    openInfo[i][j][k] = false;
                visited[i][j] = false;
            }
        }
        setOpenInfo();
        bool check = false;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(!visited[i][j]){
                    if(bfs(i, j))
                        check = true;
                }
            }
        }
        if(!check)  break;

        result++;
    }

    cout << result;

    return 0;
}