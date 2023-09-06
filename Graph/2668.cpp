//
// Created by haram on 2023-09-06
//
// Problem-Solving #2668
#include <iostream>
#include <queue>
using namespace std;
int n;
bool visited[101];
int info[101];
queue<int> ans;

bool solve(int num){
    for(int i = 1; i <= n; ++i)
        visited[i] = false;
    visited[num] = true;
    if(num == info[num])
        return true;
    int idx = info[num];
    while(!visited[idx]){
        visited[idx] = true;
        if(info[idx] == num)
            return true;
        idx = info[idx];
    }
    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> info[i];
    }
    for(int i = 1; i <= n; ++i){
        if(solve(i))
            ans.emplace(i);
    }
    cout << ans.size() << '\n';
    while(!ans.empty()){
        cout << ans.front() << '\n';
        ans.pop();
    }

    return 0;
}