//
// Created by haram on 2023-02-27.
//
#include <iostream>

using namespace std;

int input[1001];
bool visited[1001];

int groupID = 1;
void dfs(int x){
    if(visited[x]){
        groupID++;
        return;
    }

    visited[x] = true;
    dfs(input[x]);

}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 1; j <= n; j++){
            cin >> input[j];
        }
        for(int j = 1; j <= n; j++){
            if(!visited[j])
                dfs(j);
        }
        cout << groupID - 1 << '\n';
        groupID = 1;
        for(int j = 1; j <= n; j++){
            visited[j] = false;
        }
    }
    return 0;
}