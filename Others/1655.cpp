//
// Created by haram on 2023-06-28.
//
#include <iostream>
#include <queue>
using namespace std;

int n;

priority_queue<int, vector<int>, less<>> max_heap;
priority_queue<int, vector<int>, greater<>> min_heap;


void rearrange(){
    int minSize = min_heap.size();
    int maxSize = max_heap.size();

    if(minSize < maxSize){
        while (maxSize - minSize >= 2){
            min_heap.emplace(max_heap.top());
            max_heap.pop();
            maxSize--;
            minSize++;
        }
    }
    else{
        while (minSize - maxSize >= 2){
            max_heap.emplace(min_heap.top());
            min_heap.pop();
            minSize--;
            maxSize++;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    int tmp, tmp2;
    if(n == 1){
        cin >> tmp;
        cout << tmp;
        return 0;
    }
    cin >> tmp >> tmp2;
    max_heap.emplace(min(tmp, tmp2));
    min_heap.emplace(max(tmp, tmp2));


    cout << tmp << '\n' << max_heap.top() << '\n';

    for(int i = 0; i < n - 2; ++i){
        cin >> tmp;
        if(max_heap.top() >= tmp){
            max_heap.emplace(tmp);
        }
        else{
            min_heap.emplace(tmp);
        }
        rearrange();
        if(min_heap.size() < max_heap.size())
            cout << max_heap.top() << '\n';
        else if(min_heap.size() > max_heap.size())
            cout << min_heap.top() << '\n';
        else
            cout << min(max_heap.top(), min_heap.top()) << '\n';
    }
    return 0;
}