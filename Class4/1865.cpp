//
// Created by haram on 2023-04-05.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int tc;
struct edge{
    int s;
    int e;
    int t;
};
vector<edge> edges;
int table[501];
const int INF = 987654321;
int n, m, w;
bool bell(){
    for(int i = 1; i <= n - 1; ++i){
        for(int j = 0; j < edges.size(); j++){
            if(table[edges[j].e] > table[edges[j].s] + edges[j].t){
                table[edges[j].e] = table[edges[j].s] + edges[j].t;
            }
        }
    }
    for(int j = 0; j < edges.size(); j++){
        if(table[edges[j].e] > table[edges[j].s] + edges[j].t){
            cout << "YES\n";
            return true;
        }
    }
    cout << "NO\n";
    return false;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> tc;
    for(int i = 0; i < tc; ++i){
        cin >> n >> m >> w;
        edges.clear();
        for(int j = 0; j < m; ++j){
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for(int j = 0; j < w; ++j){
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -1 * t});
        }
        bell();
    }

    return 0;
}