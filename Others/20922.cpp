//
// Created by haram on 2023-08-25
//
// Problem-Solving #20922
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, k;
int count[100001];
int result;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    int cntSum = 0;
    queue<int> q;

    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        count[tmp]++;
        if(count[tmp] > k){
            result = max(result, (int)q.size());
            while(!q.empty()){
                count[q.front()]--;
                q.pop();
                if(count[tmp] <= k)
                    break;
            }
        }
        q.emplace(tmp);
    }
    result = max(result, (int)q.size());

    cout << result;

    return 0;
}