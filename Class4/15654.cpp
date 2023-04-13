//
// Created by haram on 2023-04-13.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v;
bool included[8];
void solve(string str, int index, int num){
    if(num == 1){
        str += to_string(v[index]) + "\n";
        cout << str;
        included[index] = false;
        return;
    }
    included[index] = true;
    str += to_string(v[index]) + " ";
    for(int i = 0; i < n; i++){
        if(included[i])
            continue;
        solve(str, i, num - 1);
        included[i] = false;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        pq.emplace(tmp);
    }

    while(!pq.empty()){
        v.emplace_back(pq.top());
        pq.pop();
    }

    for(int i = 0; i < n; i++){
        solve("", i, m);
        memset(included, false, sizeof(included));
    }

    return 0;
}