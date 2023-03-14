//
// Created by haram on 2023-03-11.
//
#include <iostream>
#include <queue>
#define INF 200

using namespace std;

int n, m;
char input[100][100];
int table[100][100];
queue<pair<int, int>> queue1;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve(pair<int, int> index){

    queue1.push(index);
    table[index.first][index.second] = 0;

    while(!queue1.empty()){
        int rx = queue1.front().first;
        int ry = queue1.front().second;
        queue1.pop();

        for(int i = 0; i < 4; i++){
            int nx = rx + dir[i][0];
            int ny = ry + dir[i][1];
            if(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1) {
                if(input[nx][ny] == '1'){
                    if(table[nx][ny] > table[rx][ry] + 1){
                        table[nx][ny] = table[rx][ry] + 1;
                        queue1.emplace(nx, ny);
                    }
                }
                else{
                    if(table[nx][ny] > table[rx][ry]){
                        table[nx][ny] = table[rx][ry];
                        queue1.emplace(nx, ny);
                    }
                }
            }
        }
    }
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++){
            input[i][j] = tmp[j];
            table[i][j] = INF;
        }
    }

    solve({0, 0});

    cout << table[n - 1][m - 1];

    return 0;
}