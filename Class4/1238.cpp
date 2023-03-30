//
// Created by haram on 2023-03-30.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

struct town{
    vector<pair<int, int>> next;
};

int n, m, x;
town input[1001];
int graph[1001];

int solve(int num1, int num2){
    memset(graph, 100, sizeof(graph));
    graph[num1] = 0;

    queue<pair<int, int>> q;
    q.emplace(num1, 0);

    while(!q.empty()){
        int k = q.front().first;
        int dist = q.front().second;
        q.pop();

        for(auto elem : input[k].next){
            if(dist + elem.second < graph[elem.first]){
                int _dist = dist + elem.second;
                q.emplace(elem.first, _dist);
                graph[elem.first] = _dist;
            }
        }
    }
    return graph[num2];
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> x;

    for(int i = 0; i < m; i++){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        input[tmp1].next.emplace_back(tmp2, tmp3);
    }
    int result = 0;
    for(int i = 1; i <= n; i++){
        result = max(result, solve(i, x) + solve(x, i));
    }
    cout << result;
    return 0;
}