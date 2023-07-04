//
// Created by haram on 2023-07-04
//
// Problem-Solving #2933

#include <iostream>
#include <queue>
using namespace std;

int r, c, n;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
char map[101][101];
int groups[100][100];
bool visit[100][100];

auto compare = [](pair<int, int> &x, pair<int, int> & y) -> bool{
    if(x.first > y.first)
        return false;
    else if(x.first < y.first)
        return true;
    else{
        if(x.second > y.second)
            return false;
        else
            return true;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);


void bfs_grouping(int x, int y, int group){
    groups[x][y] = group;
    int tmp = group == 1 ? 1 : 2;

    queue<pair<int, int>> q;
    q.emplace(x, y);

    while(!q.empty()){
        int _x = q.front().first;
        int _y = q.front().second;
        q.pop();
        for(const auto &elem : dir){
            int nx = _x + elem[0];
            int ny = _y + elem[1];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                if(groups[nx][ny] != tmp){
                    if(map[nx][ny] == 'x'){
                        q.emplace(nx, ny);
                        groups[nx][ny] = group;
                    }
                }
            }
        }
    }
}

int count(int x, int y, int val){
    int result = 0;
    for(int i = 1; x + i < r; ++i){
        if(x + i == r - 1)
            result = i;
        if(map[x + i][y] == 'x' && groups[x + i][y] != val){
            result = i - 1;
            break;
        }
        if(map[x + i][y] == 'x' && groups[x + i][y] == val){
            break;
        }
    }
    return result;
}

void mineral_move(int count){
    while(!pq.empty()){
        int _x = pq.top().first;
        int _y = pq.top().second;
        pq.pop();

        map[_x][_y] = '.';
        map[_x + count][_y] = 'x';
    }
}

int bfs_count(int x, int y, int group){
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            visit[i][j] = false;
    while(!pq.empty())
        pq.pop();

    visit[x][y] = true;

    queue<pair<int, int>> q;
    q.emplace(x, y);
    pq.emplace(x, y);

    int finalCount = 100;
    int val = count(x, y,group);
    finalCount = val == 0 ? finalCount : min(finalCount, val);

    while(!q.empty()){
        int _x = q.front().first;
        int _y = q.front().second;
        q.pop();

        for(const auto & elem : dir){
            int nx = _x + elem[0];
            int ny = _y + elem[1];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                if(!visit[nx][ny]){
                    if(map[nx][ny] == 'x' && groups[x][y] == group){
                        if(nx == r - 1)
                            finalCount = 0;
                        val = count(nx, ny, group);
                        finalCount = val == 0 ? finalCount : min(finalCount, val);
                        visit[nx][ny] = true;
                        pq.emplace(nx, ny);
                        q.emplace(nx, ny);
                    }
                }
            }
        }
    }
    return finalCount;
}

void print_groups(){
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j)
            cout << groups[i][j];
        cout << '\n';
    }
}

void print(){
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j)
            cout << map[i][j];
        cout << '\n';
    }
}


void remove(int i, int j){
    for(int x = 0; x < r; ++x){
        for(int y = 0; y < c; ++y)
            groups[x][y] = 0;
    }

    groups[i][j] = 0;
    map[i][j] = '.';

    for(const auto & elem : dir){
        int ni = i + elem[0];
        int nj = j + elem[1];
        if(ni >= 0 && ni < r && nj >= 0 && nj < c){
            if(map[ni][nj] == 'x'){
                bfs_grouping(ni, nj, 1);
                break;
            }
        }
    }

    for(const auto & elem : dir){
        int ni = i + elem[0];
        int nj = j + elem[1];
        if(ni >= 0 && ni < r && nj >= 0 && nj < c){
            if(map[ni][nj] == 'x' && groups[ni][nj] != 1){
                bfs_grouping(ni, nj, 2);
                break;
            }
        }
    }

    for(const auto & elem : dir){
        int ni = i + elem[0];
        int nj = j + elem[1];
        if(ni >= 0 && ni < r && nj >= 0 && nj < c){
            if(map[ni][nj] == 'x'){
                int val = bfs_count(ni, nj, groups[ni][nj]);
                if(val != 0){
                    mineral_move(val);
                    return;
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
        for(int j = 0; j < c; ++j)
            cin >> map[i][j];
    cin >> n;
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        int j = i % 2 == 0 ? 0 : c;
        for(int k = j; k < c; ++k){
            if(map[r - tmp][k] == 'x'){
                remove(r - tmp, k);
                break;
            }
        }
        for(int k = j - 1; k >= 0; --k){
            if(map[r - tmp][k] == 'x'){
                remove(r - tmp, k);
                break;
            }
        }
    }

    print();
    return 0;
}