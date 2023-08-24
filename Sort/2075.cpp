//
// Created by haram on 2023-08-24
//
// Problem-Solving #2075
#include <iostream>
#include <queue>
using namespace std;
int n;

priority_queue<int, vector<int>, greater<>> pq;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        pq.emplace(tmp);
    }

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> tmp;
            pq.emplace(tmp);
            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}