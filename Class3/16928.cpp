//
// Created by haram on 2023-03-28.
//
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int input[101];
bool visited[101];
int answer = 100;

void bfs(){
    queue<pair<int, int>> q;
    visited[1] = true;
    q.emplace(1, 0);

    while(!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(x == 100){
            answer = min(answer, cnt);
        }

        for(int i = 1; i <= 6; i++){
            int nx = x + i;
            if(nx <= 100 && !visited[nx]){
                visited[nx] = true;
                if(input[nx] != 0)
                    q.emplace(input[nx], cnt + 1);
                else
                    q.emplace(nx, cnt + 1);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        input[t1] = t2;
    }

    bfs();

    cout << answer;

    return 0;
}