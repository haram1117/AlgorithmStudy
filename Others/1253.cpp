//
// Created by haram on 2023-09-13
//
// Problem-Solving #1253
#include <iostream>
#include <queue>
using namespace std;

int n;
int info[2000];
priority_queue<int, vector<int>, greater<>> pq;

bool two_pointer(int idx){
    int num = info[idx];

    int low = 0;
    int high = n - 1;

    while(low < high){
        int sum = info[low] + info[high];
        if(low == idx){
            low++;
            continue;
        }
        if(high == idx){
            high--;
            continue;
        }

        if(sum > num)
            high--;
        else if(sum < num)
            low++;
        else
            return true;
    }
    return false;
}

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
    int i = 0;
    while(!pq.empty()){
        info[i] = pq.top();
        pq.pop();
        i++;
    }

    int answer = 0;
    for(int j = 0; j < n; ++j){
        if(two_pointer(j))
            answer++;
    }
    cout << answer;
    return 0;
}