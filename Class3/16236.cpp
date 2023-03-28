//
// Created by haram on 2023-03-27.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int input[20][20];
bool visited[20][20];
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
pair<int, int> location;
int sharkSize = 2;
int answer;
bool finished;
int cnt;

struct locStruct{
    pair<int, int> location;
    locStruct(pair<int, int> loc) : location(loc){}
    friend bool operator < (const locStruct& other1, const locStruct& other2){
        if(other1.location.first > other2.location.first)
            return true;
        else if(other1.location.first == other2.location.first){
            if(other1.location.second > other2.location.second)
                return true;
        }
        return false;
    }
};

void eat(int x, int y, int time){
    input[x][y] = 0;
    location = {x, y};
    answer += time;
    cnt++;
    if(cnt == sharkSize){
        sharkSize++;
        cnt = 0;
    }
}

void bfs(){
    queue<pair<pair<int, int>, int>> q;
    input[location.first][location.second] = 0;
    memset(visited, false, sizeof(visited));
    visited[location.first][location.second] = true;
    q.emplace(location, 0);
    priority_queue<locStruct> pq;
    int timeTmp = 0;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;
        if(timeTmp < time + 1){
            timeTmp = time + 1;
            if(!pq.empty()){
                eat(pq.top().location.first, pq.top().location.second, time);
                return;
            }
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = dir[i][0] + x;
            int ny = dir[i][1] + y;
            if(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1 && !visited[nx][ny] && input[nx][ny] <= sharkSize){
                visited[nx][ny] = true;
                pair<int, int> loc = {nx, ny};
                q.emplace(loc, time + 1);
                if(input[nx][ny] > 0 && input[nx][ny] < sharkSize){
                    pq.emplace(loc);
                }
            }
        }
    }
    finished = true;
    cout << answer;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> input[i][j];
            if(input[i][j] == 9)
                location = {i, j};
        }
    }

    while(!finished){
        bfs();
    }

    return 0;
}