//
// Created by haram on 2023-03-24.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n;

struct node{
    vector<int> next;
    node(){}
};

node nodes[100];
bool visited[100];

bool check(int i, int j){
    queue<int> q;
    memset(visited, false, sizeof(visited));
    if(nodes[i].next.empty())
        return false;
    if(i == j){
        for(auto elem : nodes[i].next){
            if(check(elem, j))
                return true;
        }
        return false;
    }
    else{
        q.emplace(i);
        visited[i] = true;
    }
    while(!q.empty()){
        int tmp = q.front();
        visited[tmp] = true;
        q.pop();

        if(tmp == j)
            return true;

        for(auto elem : nodes[tmp].next){
            if(!visited[elem]){
                q.emplace(elem);
            }
        }
    }
    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            if(tmp)
                nodes[i].next.push_back(j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << check(i, j) << " ";
        }
        cout << '\n';
    }
    return 0;
}