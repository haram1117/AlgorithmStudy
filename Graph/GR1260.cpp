//
// Created by haram on 2023-02-16.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[1001];

vector<int> graph[1001];

void dfs(int x){
    if(visited[x])
        return;
    cout << x << " ";
    visited[x] = true;
    sort(graph[x].begin(), graph[x].end());
    for(int i = 0; i < graph[x].size(); i++){
        dfs(graph[x][i]);
    }
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << " ";
        sort(graph[x].begin(), graph[x].end());
        for(int i = 0; i < graph[x].size(); i++){
            int y = graph[x][i];
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main(){
    int n, m, v;
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp2].push_back(tmp1);
        graph[tmp1].push_back(tmp2);
    }

    dfs(v);
    cout << "\n";
    memset(visited, 0, sizeof(visited));
    bfs(v);

    return 0;
}