//
// Created by haram on 2023-07-05
//
// Problem-Solving #9376

#include <iostream>
#include <queue>
#define MAX 10000;
using namespace std;

int tc;
int h, w;
char map[102][102];

int cost1[102][102];
int cost2[102][102];
int cost3[102][102];

int result;
pair<int, int> pos[2];
int posCount;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(int x, int y, int cost[][102]){
    for(int i = 0; i <= h + 1; ++i){
        for(int j = 0; j <= w + 1; ++j)
            cost[i][j] = MAX;
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.emplace(0, make_pair(x, y));
    cost[x][y] = 0;


    while(!pq.empty()){
        int p = pq.top().first;
        int _x = pq.top().second.first;
        int _y = pq.top().second.second;
        pq.pop();

        for(const auto & elem : dir){
            int nx = _x + elem[0];
            int ny = _y + elem[1];

            if(nx >= 0 && nx <= h + 1 && ny >= 0 && ny <= w + 1){
                if(map[nx][ny] == '#'){
                    if(cost[nx][ny] > p + 1){
                        pq.emplace(p + 1, make_pair(nx, ny));
                        cost[nx][ny] = p + 1;
                    }
                }
                else if(map[nx][ny] == '.' || map[nx][ny] == '$'){
                    if(cost[nx][ny] > p){
                        pq.emplace(p, make_pair(nx, ny));
                        cost[nx][ny] = p;
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

    cin >> tc;
    for(int k = 0; k < tc; ++k){
        // 초기화
        posCount = 0;
        result = MAX;

        // 입력
        cin >> h >> w;
        for(int j = 0; j <= w + 1; ++j){
            map[0][j] = '.';
            map[h + 1][j] = '.';
            for(int i = 0; i <= h + 1; ++i){
                cost1[j][i] = MAX;
                cost2[j][i] = MAX;
                cost3[j][i] = MAX;
            }
        }
        for(int i = 1; i <= h; ++i){
            map[i][0] = '.';
            map[i][w + 1] = '.';
            for(int j = 1; j <= w; ++j){
                cin >> map[i][j];
                if(map[i][j] == '$') {
                    pos[posCount].first = i;
                    pos[posCount].second = j;
                    posCount++;
                }
            }
        }

        // 풀이

        bfs(0, 0, cost1);
        bfs(pos[0].first, pos[0].second, cost2);
        bfs(pos[1].first, pos[1].second, cost3);

        for(int i = 1; i <= h; ++i){
            for(int j = 1; j <= w; ++j){
                if(map[i][j] == '#')
                    result = min(result, cost1[i][j] + cost2[i][j] + cost3[i][j] - 2);
                else if((i == 1 || j == 1 || i == h || j == w))
                    result = min(result, cost1[i][j] + cost2[i][j] + cost3[i][j]);
            }
        }

        // 출력
        cout << result << '\n';
    }

    return 0;
}