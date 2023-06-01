//
// Created by haram on 2023-06-01.
//
#include <iostream>
#include <stack>

using namespace std;
int n, k;
int planet[10][10];
bool visited[10];
int result = 987654321;

void floyd(){
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                planet[i][j] = min(planet[i][j], planet[i][k] + planet[k][j]);
            }
        }
    }
}

void dfs(int index, int dist, int cnt){
    if(cnt >= n){
        result = min(result, dist);
        return;
    }
    for(int i = 0; i < n; ++i){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, dist + planet[index][i], cnt + 1);
        visited[i] = false;
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> planet[i][j];
        }
    }
    floyd();

    visited[k] = true;
    dfs(k, 0, 1);

    cout << result;


    return 0;
}