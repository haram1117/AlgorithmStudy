//
// Created by haram on 2023-09-04
//
// Problem-Solving #20437
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
string str;
int t, k;
unordered_map<char, queue<int>> info;
int result1, result2;
void solve(){
    result1 = 987654321;
    result2 = 0;
    for(int i = 0; i < str.length(); ++i){
        if(info[str[i]].size() < k - 1){
            info[str[i]].emplace(i);
        }
        else{
            int len = i - info[str[i]].front() + 1;
            result1 = min(result1, len);
            result2 = max(result2, len);
            info[str[i]].pop();
            info[str[i]].emplace(i);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--){
        cin >> str >> k;
        if(k == 1)
            result1 = 1, result2 = 1;
        else{
            info.clear();
            solve();
        }
        if(result1 == 987654321)
            cout << -1 << '\n';
        else
            cout << result1 << " " << result2 << '\n';
    }
    return 0;
}