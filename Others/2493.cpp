//
// Created by haram on 2023-08-18.
//
#include <iostream>
#include <stack>
using namespace std;

int n;
int tower[500001];
int answer[500001];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> tower[i];
    }

    stack<pair<int, int>> s;
    for(int i = n - 1; i >= 1; --i){
        if(tower[i] >= tower[i + 1]){
            answer[i + 1] = i;
            while(!s.empty()){
                pair<int, int> top = s.top();
                if(tower[i] >= top.second){
                    answer[top.first] = i;
                    s.pop();
                }
                else
                    break;
            }
        }
        else{
            s.emplace(i + 1, tower[i + 1]);
        }
    }

    for(int i = 1; i <= n; ++i)
        cout << answer[i] << " ";

    return 0;
}