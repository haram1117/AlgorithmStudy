//
// Created by haram on 2023-04-17.
//
#include <iostream>
#include <queue>
using namespace std;

int n, k;
const int INF = 987654321;
bool visited[100001];
int table[100001];

void bfs(){
    for(int i = 0; i <= 100000; ++i)
        table[i] = INF;
    queue<pair<int, int>> q;
    q.emplace(n, 0);
    table[n] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int time = q.front().second;
        q.pop();

        if(time > table[x])
            continue;

        if(2 * x <= 100000){
            if(!visited[2 * x] && table[2 * x] > time){
                q.emplace(2 * x, time);
                table[2 * x] = time;
                visited[2 * x] = true;
            }
        }
        if(x - 1 >= 0){
            if(!visited[x - 1] && table[x - 1] > time + 1){
                q.emplace(x - 1, time + 1);
                table[x - 1] = time + 1;
                visited[x - 1] = true;
            }
        }
        if(x + 1 <= 100000){
            if(!visited[x + 1] && table[x + 1] > time + 1){
                q.emplace(x + 1, time + 1);
                table[x + 1] = time + 1;
                visited[x + 1] = true;
            }
        }
    }
}

int main(){
    cin >> n >> k;
    bfs();

    cout << table[k];

    return 0;
}