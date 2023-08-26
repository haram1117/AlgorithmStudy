//
// Created by haram on 2023-08-26
//
// Problem-Solving #1446
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, d;
vector<pair<int, int>> shortCuts[10001];
int dist[10001];
int result;
void bfs(){
    queue<pair<int, int>> q;
    for(auto elem : shortCuts[0]){
        if(dist[elem.first] > elem.second){
            q.emplace(elem);
            dist[elem.first] = elem.second;
        }
    }
    q.emplace(1, 1);
    dist[1] = 1;

    while(!q.empty()){
        int end = q.front().first;
        int distance = q.front().second;
        if(end == d)
            result = min(result, distance);
        q.pop();

        for(auto elem : shortCuts[end]){
            if(dist[elem.first] > elem.second + distance){
                q.emplace(elem.first, elem.second + distance);
                dist[elem.first] = elem.second + distance;
            }
        }
        if(dist[end + 1] > distance + 1){
            q.emplace(end + 1, distance + 1);
            dist[end + 1] = distance + 1;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> d;
    for(int i = 0; i < n; ++i){
        int s, e, l;
        cin >> s >> e >> l;
        shortCuts[s].emplace_back(e, l);
    }

    memset(dist, 10001, sizeof(dist));
    result = d;

    bfs();

    cout << result;

    return 0;
}