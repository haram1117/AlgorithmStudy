//
// Created by haram on 2023-02-18.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool visited[100][100];
int map[100][100];

int result = 197;
int groupNum = 2;
int n;

int adjacent[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


void mapGrouping(int x, int y){
    if(visited[x][y])
        return;

    visited[x][y] = 1;

    if(map[x][y] == 1){
        map[x][y] = groupNum;
        if(x >= 1)
            mapGrouping(x - 1, y);
        if(x <= n - 2)
            mapGrouping(x + 1, y);

        if(y >= 1)
            mapGrouping(x, y - 1);
        if(y <= n - 2)
            mapGrouping(x, y + 1);
    }
}

int bridge(int groupID){
    int resultVal = 0;
    queue<pair<int, int>> queue1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == groupID){
                visited[i][j] = true;
                queue1.emplace(i, j);
            }
        }
    }

    while(!queue1.empty()){
        int s = queue1.size();
        for(int j = 0; j < s; j++){
            int x = queue1.front().first;
            int y = queue1.front().second;

            queue1.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + adjacent[i][0];
                int ny = y + adjacent[i][1];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                    if(map[nx][ny] != 0 && map[nx][ny] != groupID)
                        return resultVal;
                    if(map[nx][ny] == 0 && !visited[nx][ny]){
                        visited[nx][ny] = true;
                        queue1.emplace(nx, ny);
                    }
                }
            }
        }
        resultVal++;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1){
                mapGrouping(i, j);
                i = -1;
                j = -1;
                groupNum++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    for(int i = 2; i < groupNum; i++){
        result = min(result, bridge(i));
        memset(visited, 0, sizeof(visited));
    }

    cout << result;


    return 0;
}