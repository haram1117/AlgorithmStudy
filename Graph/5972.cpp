//
// Created by haram on 2023-09-04
//
// Problem-Solving #5972
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int visited[50001];
const int MAX = 987654321;
vector<pair<int, int>> road[50001];

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 1);
    visited[1] = 0;

    while(!pq.empty()){
        int price = pq.top().first;
        int dest = pq.top().second;
        pq.pop();

        if(visited[dest] < price)
            continue;

        for(int i = 0; i < road[dest].size(); ++i){
            if(visited[road[dest][i].first] > price + road[dest][i].second){
                visited[road[dest][i].first] = price + road[dest][i].second;
                pq.emplace(visited[road[dest][i].first], road[dest][i].first);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        road[a].emplace_back(b, c);
        road[b].emplace_back(a, c);
    }

    for(int i = 1; i <= n; ++i)
        visited[i] = MAX;

    dijkstra();

    cout << visited[n];

    return 0;
}