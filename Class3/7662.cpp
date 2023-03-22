//
// Created by haram on 2023-03-22.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

priority_queue<pair<int, int>> maxHeap;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
int t, k;

bool removed[1000000];
void insert(int num, int idx){
    minHeap.emplace(num, idx);
    maxHeap.emplace(num, idx);
}
void remove(int num){
    if(num == 1){
        while(!maxHeap.empty()){
            if(removed[maxHeap.top().second])
                maxHeap.pop();
            else
                break;
        }
        if(maxHeap.empty())
            return;
        removed[maxHeap.top().second] = true;
        maxHeap.pop();
    }
    else{
        while(!minHeap.empty()){
            if(removed[minHeap.top().second])
                minHeap.pop();
            else
                break;
        }
        if(minHeap.empty())
            return;
        removed[minHeap.top().second] = true;
        minHeap.pop();
    }
}

void result(){
    while(!minHeap.empty()){
        if(removed[minHeap.top().second])
            minHeap.pop();
        else
            break;
    }
    while(!maxHeap.empty()){
        if(removed[maxHeap.top().second])
            maxHeap.pop();
        else
            break;
    }
    if(minHeap.empty()){
        cout << "EMPTY\n";
    }
    else{
        cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
    }
    while(!maxHeap.empty())
        maxHeap.pop();
    while(!minHeap.empty())
        minHeap.pop();
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            char command;
            int num;
            cin >> command >> num;
            if(command == 'I'){
                insert(num, j);
            }
            else if(command == 'D'){
                remove(num);
            }
        }
        result();
        memset(removed, false, sizeof(bool) * 1000000);
    }
    return 0;
}