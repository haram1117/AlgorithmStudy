//
// Created by haram on 2023-04-04.
//
#include <iostream>
#include <queue>
using namespace std;
int v, e;
int k;
const int INF = 987654321;
int table[20001];
vector<pair<int, int>> info[20001];

void dijk(){
    table[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(0, k);
    while(!q.empty()){
        int dist = q.top().first;
        int dest = q.top().second;
        q.pop();

        for(const auto &elem : info[dest]){
            if(table[elem.first] > dist + elem.second){
                table[elem.first] = dist + elem.second;
                q.emplace(dist + elem.second, elem.first);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> v >> e >> k;
    for(int i = 0; i < e; i++){
        int u, v1, w;
        cin >> u >> v1 >> w;
        info[u].emplace_back(v1, w);
    }

    for(int i = 1; i <= v; i++) table[i] = INF;

    dijk();

    for(int i = 1; i <= v; i++){
        if(table[i] == INF)
            cout << "INF\n";
        else
            cout << table[i] << '\n';
    }

    return 0;
}