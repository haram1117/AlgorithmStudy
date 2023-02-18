//
// Created by haram on 2023-02-17.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct node{
    int id;
    int dist;
};


bool visited[10001];
vector<node> graph[10001];

int maxLen = 0;
int maxNode = 0;
void dfs(int x, int dist){
    if(visited[x])
        return;

    visited[x] = true;
    if(maxLen < dist) {
        maxLen = dist;
        maxNode = x;
    }

    for(auto elem : graph[x]){
        if(!visited[elem.id]){
            dfs(elem.id, dist + elem.dist);
        }
    }
}
int n;
int p, c, d;
int main(){
    freopen("input.txt", "r", stdin);
    cin >> n;
    while(cin >> p >> c >> d){
        graph[p].push_back({c, d});
        graph[c].push_back({p, d});
    }
    dfs(1, 0);
    maxLen = 0;
    memset(visited, 0, sizeof(visited));
    dfs(maxNode, 0);
    cout << maxLen << "\n";
}