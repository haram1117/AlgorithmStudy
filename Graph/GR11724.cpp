//
// Created by haram on 2023-02-27.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> input[1001];
bool visited[1001];

int groupNum = 1;
void dfs(int x){

    visited[x] = true;
    for(auto elem : input[x]){
        if(!visited[elem])
            dfs(elem);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int node1;
        cin >> node1;
        int node2;
        cin >> node2;
        input[node1].push_back(node2);
        input[node2].push_back(node1);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            groupNum++;
        }
    }

    cout << groupNum - 1;

    return 0;
}