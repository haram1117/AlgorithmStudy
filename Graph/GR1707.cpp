//
// Created by haram on 2023-02-17.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct node{
    int setId = -1;
    vector<int> children;
};


bool visited[20001];
bool result = true;
void bfs(node graph[], int x, int n){
    if(visited[x])
        return;

    graph[x].setId = 0;
    visited[x] = true;
    queue<int> queue1;
    for (auto elem : graph[x].children) {
        graph[elem].setId = 1;
        queue1.push(elem);
        visited[elem] = 1;
    }
    while (!queue1.empty()){
        int tmp = queue1.front();
        queue1.pop();

        for (auto elem : graph[tmp].children){
            int val = graph[tmp].setId;

            if(graph[elem].setId == -1){
                queue1.push(elem);
                graph[elem].setId = graph[tmp].setId ? 0 : 1;
                visited[elem] = 1;
            }
            else if(graph[elem].setId == val){
                result = false;
                return;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            bfs(graph, i, n);
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k;
    cin >> k;

    for(int i = 0; i < k; i++){
        node graph[20001];
        int v, e;
        cin >> v >> e;
        for(int j = 0; j < e; j++){
            int u, v1;
            cin >> u >> v1;
            graph[u].children.push_back(v1);
            graph[v1].children.push_back(u);
        }
        bfs(graph, 1, v);
        if(!result)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
        memset(visited, 0, 20001);
        result = true;
    }

    return 0;
}