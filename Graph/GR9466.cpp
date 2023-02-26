//
// Created by haram on 2023-02-24.
//
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int input[100001];
bool visited[100001];
int team[100001];
int teamNo = 1;
queue<int> q1;

void dfs(int x){
    if(team[x] == teamNo){ // 팀 결성
        while(!q1.empty()){
            if(q1.front() == x){
                break;
            }
            if(team[q1.front()] == teamNo)
                team[q1.front()] = -1;
            q1.pop();
        }
        teamNo++;
        while(!q1.empty())
            q1.pop();
        return;
    }

    if(visited[x] || (visited[input[x]] && team[input[x]] != teamNo)){

        visited[x] = true;
        while(!q1.empty()){
            team[q1.front()] = -1;
            q1.pop();
        }
        while(!q1.empty())
            q1.pop();
        return;
    }

    visited[x] = true;

    if(team[x] == -1){
        team[x] = teamNo;
        q1.push(x);
        dfs(input[x]);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        memset(visited, 0, (n + 1) * sizeof(bool));
        memset(team, -1, (n + 1) * sizeof(int));
        for(int j = 1; j <= n; j++){
            cin >> input[j];
        }
        for(int j = 1; j <= n; j++){
            dfs(j);
        }
        teamNo = 1;
        int result = 0;
        for(int j = 1; j <= n; j++){
            if(team[j] == -1)
                result++;
        }
        cout << result << "\n";
    }
    return 0;
}