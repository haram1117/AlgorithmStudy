//
// Created by haram on 2023-08-23
//
// Problem-Solving #11501
#include <iostream>
#include <queue>
using namespace std;
int t, n;
int info[1000000];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--){
        cin >> n;
        long long result = 0;
        int count = 0;

        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < n; ++i){
            cin >> info[i];
            pq.emplace(info[i], i);
        }

        int idx = 0;
        bool check = false;
        for(int i = 0; i < n; ++i){
            while(!pq.empty() && !check){
                if(pq.top().second >= idx){
                    idx = pq.top().second;
                    pq.pop();
                    check = true;
                    break;
                }
                pq.pop();
            }

            if(i < idx){
                count++;
                result -= info[i];
            }
            else if(i == idx){
                result += info[i] * (long long) count;
                count = 0;
                check = false;
            }
        }
        cout << result << '\n';
    }

    return 0;
}