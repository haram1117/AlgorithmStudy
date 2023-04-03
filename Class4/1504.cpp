//
// Created by haram on 2023-04-03.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n, e;
const int INF = 987654321;
int v1, v2;
struct node{
    vector<pair<int, int>> next;
};

node vec[801];
int table[801];

void solve(int start){
    for(int i = 0; i <= n; i++)
        table[i] = INF;

    queue<pair<int, int>> q;
    q.emplace(start, 0);
    table[start] = 0;

    while(!q.empty()){
        int tmp = q.front().first;
        int dist = q.front().second;
        q.pop();

        for(auto elem : vec[tmp].next){
            if(table[elem.first] > dist + elem.second){
                table[elem.first] = dist + elem.second;
                q.emplace(elem.first, dist + elem.second);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int f, l, p;
        cin >> f >> l >> p;
        vec[f].next.emplace_back(l, p);
        vec[l].next.emplace_back(f, p);
    }
    cin >> v1 >> v2;
    solve(1);
    int sv1 = table[v1];
    int sv2 = table[v2];

    solve(v1);
    int v1v2 = table[v2];
    int v1n = table[n];

    solve(v2);
    int v2n = table[n];

    int result = sv1 + v1v2 + v2n;
    result = min(result, sv2 + v1v2 + v1n);

    if(v1v2 >= INF || result >= INF){
        cout << -1;
        return 0;
    }

    cout << result;

    return 0;
}