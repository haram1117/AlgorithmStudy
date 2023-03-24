//
// Created by haram on 2023-03-24.
//
#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int, deque<int>, less<int>> pq;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == 0){
            if(pq.empty())
                cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.emplace(tmp);
    }

    return 0;
}