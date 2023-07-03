//
// Created by haram on 2023-06-28.
//
#include <iostream>
#include <queue>
using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int r, c;
int map[1500][1500];
pair<int, int> swans[2] = {{-1, -1}, {-1, -1}};
queue<pair<int, int>> meltQ;
queue<pair<int, int>> meltQ2;
bool visited[1500][1500];
int maxNum;

void melt(){
    int num = 1;
    while(!meltQ.empty() || !meltQ2.empty()){
        while(!meltQ.empty()){
            int x = meltQ.front().first;
            int y = meltQ.front().second;
            meltQ.pop();

            for(const auto &i : dir){
                int nx = x + i[0];
                int ny = y + i[1];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                    if(map[nx][ny] == -1){
                        map[nx][ny] = num;
                        meltQ2.emplace(nx, ny);
                    }
                }
            }
        }
        num++;
        while(!meltQ2.empty()){
            int x = meltQ2.front().first;
            int y = meltQ2.front().second;
            meltQ2.pop();

            for(const auto &i : dir){
                int nx = x + i[0];
                int ny = y + i[1];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                    if(map[nx][ny] == -1){
                        map[nx][ny] = num;
                        meltQ.emplace(nx, ny);
                    }
                }
            }
        }
        maxNum = num;
        num++;
    }
}

bool swanFind(int day){
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j)
            visited[i][j] = false;
    }
    queue<pair<int, int>> q;
    q.emplace(swans[0]);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(const auto & i : dir){
            int nx = x + i[0];
            int ny = y + i[1];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                if(nx == swans[1].first && ny == swans[1].second)
                    return true;
                if(!visited[nx][ny]){
                    if(map[nx][ny] <= day){
                        visited[nx][ny] = true;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
    }
    return false;
}

int binary_search(){
    int low = 1;
    int high = maxNum;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(swanFind(mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;

    char tmp;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cin >> tmp;
            if(tmp == '.'){
                map[i][j] = 0;
                meltQ.emplace(i, j);
            }
            else if(tmp == 'X')
                map[i][j] = -1;
            else{
                map[i][j] = 0;
                meltQ.emplace(i, j);
                if(swans[0].first == -1){
                    swans[0].first = i;
                    swans[0].second = j;
                }
                else{
                    swans[1].first = i;
                    swans[1].second = j;
                }
            }
        }
    }
    melt();
    cout << binary_search();
    return 0;
}