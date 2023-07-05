//
// Created by haram on 2023-07-05
//
// Problem-Solving #9376

#include <iostream>
#include <queue>
#define MAX 987654321;
using namespace std;

int tc;
int h, w;
char map[100][100];
int cost[100][100];
int cost2[100][100];
int result;
pair<int, int> pos[2];
int posCount;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void print(){
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j)
            cout << cost[i][j] << '\t';
        cout << '\n';
    }
    cout << '\n';
}

void bfs(int x, int y, int price){
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j)
            cost2[i][j] = MAX;
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.emplace(price, make_pair(x, y));
    cost2[x][y] = price;


    while(!pq.empty()){
        int p = pq.top().first;
        int _x = pq.top().second.first;
        int _y = pq.top().second.second;
        pq.pop();

        if(_x == 0 || _x == h - 1 || _y == 0 || _y == w - 1){
            result = min(result, p);
            return;
        }

        for(const auto & elem : dir){
            int nx = _x + elem[0];
            int ny = _y + elem[1];

            if(nx >= 0 && nx < h && ny >= 0 && ny < w){
                if(map[nx][ny] == '#'){
                    if(cost2[nx][ny] > p + 1){
                        pq.emplace(p + 1, make_pair(nx, ny));
                        cost2[nx][ny] = p + 1;
                    }
                }
                else if(map[nx][ny] == '.' || map[nx][ny] == '$'){
                    if(cost2[nx][ny] > p){
                        pq.emplace(p, make_pair(nx, ny));
                        cost2[nx][ny] = p;
                    }
                }
            }
        }
    }
}

void dfs(int x, int y, int price){
    cost[x][y] = price;

    if(x == 0 || x == h - 1 || y == 0 || y == w - 1 || (x == pos[1].first && y == pos[1].second)){
        bfs(pos[1].first, pos[1].second, price);
    }

    for(const auto & elem : dir){
        int nx = x + elem[0];
        int ny = y + elem[1];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w){
            if(map[nx][ny] == '.' || map[nx][ny] == '$'){
                if(cost[nx][ny] > price){
                    cost[nx][ny] = price;
                    dfs(nx, ny, price);
                }
            }
            else if(map[nx][ny] == '#'){
                if(cost[nx][ny] > price + 1){
                    cost[nx][ny] = price + 1;
                    map[nx][ny] = '.';
                    dfs(nx, ny, price + 1);
                    map[nx][ny] = '#';
                }
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> tc;
    for(int k = 0; k < tc; ++k){
        // 초기화
        posCount = 0;
        result = MAX;

        // 입력
        cin >> h >> w;
        for(int i = 0; i < h; ++i)
            for(int j = 0; j < w; ++j){
                cin >> map[i][j];
                if(map[i][j] == '$') {
                    pos[posCount].first = i;
                    pos[posCount].second = j;
                    posCount++;
                }
                cost[i][j] = MAX;
            }

        // 풀이
        dfs(pos[0].first, pos[0].second, 0);

        // 출력
        cout << result << '\n';
    }

    return 0;
}