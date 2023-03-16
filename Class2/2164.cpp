//
// Created by haram on 2023-03-16.
//
#include <iostream>
#include <queue>
using namespace std;
int n;
queue<int> q;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    int result;
    bool idx = false;
    while(!q.empty()){
        if(idx){
            result = q.front();
            q.pop();
            q.push(result);
        }
        else{
            result = q.front();
            q.pop();
        }
        idx = !idx;
    }

    cout << result;
    return 0;
}