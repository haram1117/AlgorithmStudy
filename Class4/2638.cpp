//
// Created by haram on 2023-04-17.
//
#include <iostream>
#include <queue>
using namespace std;
int n, m;
int input[100][100];
bool visited[100][100];
int cnt;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool canMelt;
bool checkall(){
    if(canMelt){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(input[i][j] == 2)
                    input[i][j] = -1;
                else if(input[i][j] == 0) // 안쪽 공기와 바깥쪽 공기를 구분할 때 input 값이 -1 부터 시작하는데 그걸 초기화를 안해줘서 시간초과가 났다.
                    input[i][j] = -1; // solve() 의 bfs queue안에 (0, 0)에서부터 바깥공기를 따라 0으로 초기화시켜줘야 하는데 -1로 초기화를 안해주면 바깥공기를 따라 갈 수 없다.
            }
        }
        canMelt = false;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(input[i][j] == 1)
                return false;
        }
    }
    return true;
}

void setInner(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)
            visited[i][j] = false;
    }

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visited[0][0] = true;
    input[0][0] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(!visited[nx][ny] && input[nx][ny] == -1){
                    q.emplace(nx, ny);
                    visited[nx][ny] = true;
                    input[nx][ny] = 0;
                }
            }
        }
    }

}

void solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(input[i][j] == 1){
                int count = 0;
                for(int _i = 0; _i < 4; ++_i){
                    int nx = i + dir[_i][0];
                    int ny = j + dir[_i][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                        if(input[nx][ny] == 0){
                            count++;
                            canMelt = true;
                        }
                    }
                }
                if(count >= 2){
                    input[i][j] = 2;// 녹음
                    visited[i][j] = true;
                }
            }
        }
    }
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int tmp;
            cin >> tmp;
            if(tmp == 1)
                input[i][j] = tmp;
            else if(tmp == 0)
                input[i][j] = -1;
        }
    }
    while(true){
        // 내부 공기 정의
        setInner();
        // 사라지는 격자 Update
        solve();
        cnt++;
        if(checkall())
            break;
    }

    cout << cnt;

    return 0;
}