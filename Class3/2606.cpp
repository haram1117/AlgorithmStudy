//
// Created by haram on 2023-03-20.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> input[101];
bool visited[101];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        input[tmp1].push_back(tmp2);
        input[tmp2].push_back(tmp1);
    }

    int result = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty())
    {
        vector<int> tmpVec = input[q.front()];
        q.pop();
        for(auto elem : tmpVec){
            if(!visited[elem]){
                result++;
                visited[elem] = true;
                q.push(elem);
            }
        }
    }

    cout << result;
    return 0;
}