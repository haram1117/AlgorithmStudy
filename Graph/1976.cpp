//
// Created by haram on 2023-08-18.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int plan[1000];
vector<vector<int>> info_vec;
bool visited[201];

bool bfs(int start, int end){
    for(int j = 1; j <= n; ++j)
        visited[j] = false;
    visited[start] = true;
    queue<int> q;
    q.emplace(start);

    while(!q.empty()){
        int x = q.front();
        if(x == end)
            return true;
        q.pop();

        for(const auto & elem : info_vec[x]){
            if(!visited[elem]){
                q.emplace(elem);
                visited[elem] = true;
            }
        }
    }
    return false;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    info_vec.resize(n + 1);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int tmp;
            cin >> tmp;
            if(tmp == 1)
                info_vec[i].emplace_back(j);
        }
    }
    for(int i = 0; i < m; ++i)
        cin >> plan[i];

    bool result = true;
    for(int i = 0; i < m - 1; ++i){
        if(!bfs(plan[i], plan[i + 1])){
            result = false;
            break;
        }
    }

    if(result)  cout << "YES";
    else    cout << "NO";

    return 0;
}