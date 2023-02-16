//
// Created by haram on 2023-02-16.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


struct node{
    int id;
    int length;
};


bool visited[100001];
vector<node> graph[100001];
int maxLen;
int lastNode;
void dfs(int x, int distance){
    if(visited[x])
        return;
    visited[x] = true;
    if(maxLen < distance){
        maxLen = distance;
        lastNode = x;
    }
    for(int i = 0; i < graph[x].size(); i++){
        if(visited[graph[x][i].id])
            continue;
        dfs(graph[x][i].id, distance + graph[x][i].length);
    }
}

int main(){
    int n;
    cin >> n;

    bool check = true;
    for(int i = 1; i <= n; i++){
        int id, tmp, tmp2;
        if(check){
            cin >> id;
            check = false;
        }
        cin >> tmp;
        if(tmp == -1){
            check = true;
            continue;
        }
        cin >> tmp2;
        graph[id].push_back({tmp, tmp2});
        i--;
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    maxLen = 0;
    dfs(lastNode, maxLen);

    cout << maxLen << '\n';
    return 0;
}