//
// Created by haram on 2023-03-16.
//
#include <iostream>
#include <queue>
using namespace std;

struct document{
    int importance;
    int id;
    document(int _importance, int _id) : importance(_importance), id(_id){}
};

int t;
int n, m;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        queue<document> q;
        priority_queue<int> importance;
        for(int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            importance.emplace(tmp);
            q.emplace(tmp, j);
        }
        int result = 0;
        while(!q.empty()){
            if(q.front().importance == importance.top()){
                if(q.front().id == m){
                    result++;
                    break;
                }
                q.pop();
                result++;
                importance.pop();
            }else{
                auto tmp = q.front();
                q.pop();
                q.emplace(tmp);
            }
        }
        cout << result << '\n';
    }
    return 0;
}