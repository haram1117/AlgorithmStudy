//
// Created by haram on 2023-03-21.
//
#include <iostream>
#include <vector>
using namespace std;
int n, m;
string s;
int result;
vector<int> cnts;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i + 2 < m; i++){
        if(s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I'){
            i++;
            cnt++;
        }
        else{
            if(cnt != 0)
                cnts.push_back(2 * cnt + 1);
            cnt = 0;
        }
    }
    if(cnt != 0)
        cnts.push_back(2 * cnt + 1);

    int len = 2 * n + 1;
    for(auto elem : cnts){
        if(elem - len >= 0)
            result += (elem - len) / 2 + 1;
    }

    cout << result;
    return 0;
}