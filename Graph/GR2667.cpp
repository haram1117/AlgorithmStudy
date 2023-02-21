//
// Created by haram on 2023-02-21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int graph[26][26];
bool visited[26][26];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n;
vector<int> houseNum;
int groupID;
void bfs(int x, int y){
    queue<pair<int, int>> queue1;
    queue1.emplace(x, y);
    visited[x][y] = true;
    graph[x][y] = groupID;
    houseNum.push_back(1);

    while(!queue1.empty()){
        x = queue1.front().first;
        y = queue1.front().second;
        queue1.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n){
                if(!visited[nx][ny] && graph[nx][ny] == 1){
                    queue1.emplace(nx, ny);
                    visited[nx][ny] = true;
                    graph[nx][ny] = groupID;
                    houseNum[groupID - 2]++;
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char tmp;
            cin >> tmp;
            graph[i][j] = tmp - '0';
        }
    }
    groupID = 2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == 1){
                bfs(i, j);
                i = 0;
                j = 0;
                groupID++;
            }
        }
    }

    cout << groupID - 2 << "\n";
    sort(houseNum.begin(), houseNum.end());
    for(int i = 0; i < groupID - 2; i++){
        cout << houseNum[i] << "\n";
    }



    return 0;
}