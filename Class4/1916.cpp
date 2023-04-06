//
// Created by haram on 2023-04-06.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;
int n, m;
int table[1001];
vector<pair<int, int>> edge[1001];
int s, e;

void solve(){
    for(int i = 1; i <= n; i++) table[i] = INF;
    table[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);

    while(!pq.empty()){
        int price = pq.top().first;
        int loc = pq.top().second;
        pq.pop();
        if(table[loc] < price) // 지금 꺼낸 정점이 무시해도 되는 정점이다. (이미 넘어버림)
            continue;
        for(const auto & elem : edge[loc]){
            if(table[elem.second] > price + elem.first){
                table[elem.second] = price + elem.first;
                pq.emplace(price + elem.first, elem.second);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        edge[t1].emplace_back(t3, t2);
    }
    cin >> s >> e;
    solve();
    cout << table[e];
    return 0;
}