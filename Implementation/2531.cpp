//
// Created by haram on 2023-08-30
//
// Problem-Solving #2531
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
int n, d, k, c;
int info[30000];
queue<int> q;
unordered_map<int, int> m;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> d >> k >> c;

    for(int i = 0; i < n; ++i){
         cin >> info[i];
    }
    m[c] = 1;

    int result = 0;
    int count = 1;
    for(int i = 0; i < k; ++i){
        q.emplace(info[i]);
        m[info[i]]++;
        if(m[info[i]] == 1)
            count++;
    }
    result = count;
    for(int i = k; i < n + k - 1; ++i){
        m[q.front()]--;
        if(m[q.front()] == 0)   count--;
        q.pop();

        int idx = i;
        if(idx >= n){
            idx -= n;
        }

        q.emplace(info[idx]);
        m[info[idx]]++;
        if(m[info[idx]] == 1)
            count++;

        result = max(result, count);
    }

    cout << result;

    return 0;
}