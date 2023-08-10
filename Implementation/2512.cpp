//
// Created by haram on 2023-08-10
//
// Problem-Solving #2512
#include <iostream>
#include <queue>
using namespace std;

int n, m;
priority_queue<int, vector<int>, greater<>> pq;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        pq.emplace(tmp);
    }
    cin >> m;
    int answer = 0;
    while(!pq.empty()){
        if(pq.top() > (m / pq.size()))
        {
            int tmp = m / pq.size();
            answer = max(answer, tmp);
            break;
        }
        answer = max(answer, pq.top());
        m -= pq.top();
        pq.pop();
    }

    cout << answer;
    return 0;
}