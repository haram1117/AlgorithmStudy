//
// Created by haram on 2023-02-27.
//
#include <iostream>
#include <vector>
using namespace std;

int result[100001];
vector<int> input[100001];
int n;

void dfs(int x){
    for(auto it = input[x].begin(); it != input[x].end(); it++){
        if(!result[*it]){
            result[*it] = x;
            dfs(*it);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 2; i <= n; i++){
        int node1, node2;
        cin >> node1 >> node2;
        input[node1].push_back(node2);
        input[node2].push_back(node1);
    }
    dfs(1);
    for(int i = 2; i <= n; i++){
        cout << result[i] << "\n";
    }

    return 0;
}