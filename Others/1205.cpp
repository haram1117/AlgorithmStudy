//
// Created by haram on 2023-08-08
//
// Problem-Solving #1205

#include <iostream>
#include <queue>
using namespace std;

typedef unsigned long long ull;

int n, p;
ull score;
priority_queue<ull , vector<ull>, less<>> pq;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> score >> p;
    for(int i = 0; i < n; ++i){
        ull tmp;
        cin >> tmp;
        pq.emplace(tmp);
    }


    int result = 1;
    int tmp = 0;
    while(!pq.empty()){
        if(pq.top() == score){
            tmp++;
        }
        else if(pq.top() < score){
            break;
        }
        result++;
        pq.pop();
    }

    if(result > p)
        cout << -1;
    else
        cout << result - tmp;
    return 0;
}