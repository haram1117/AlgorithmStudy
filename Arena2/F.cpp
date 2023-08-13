//
// Created by haram on 2023-08-13
//
// Problem-Solving #F
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

int t, n;
int mult;
vector<vector<pair<char, int>>> v(n);
bool dfs(int idx, ull k, pair<char, int> str){
    if(str.first == '+')
        k += str.second;
    else
        k *= str.second;

    idx++;
    if(idx >= n)
    {
        if(k % 7 == 0)
            return true;
        else
            return false;
    }

    if(k % 7 == 0){
        if(idx > mult)
            return true;
    }

    for(int i = 0; i < 2; ++i){
        if(dfs(idx, k, v[idx][i]))
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        ull k = 1;
        cin >> n;
        v.clear();
        v.resize(n);
        cin.ignore();
        bool check = false;
        for(int j = 0; j < n; ++j)
        {
            string str;
            getline(cin, str);
            if((str[0] == '*' && str[2] == '7') || (str[4] == '*' && str[6] == '7'))
                check = true;
            else if(str[0] == '+' && str[4] == '+'){
                check = false;
                mult = j;
            }
            v[j].emplace_back(str[0], str[2] - '0');
            v[j].emplace_back(str[4], str[6] - '0');
        }
        if(check){
            cout << "LUCKY\n";
            continue;
        }
        if(dfs(0, k, v[0][0]))
            cout << "LUCKY\n";
        else if(dfs(0, k, v[0][1]))
            cout << "LUCKY\n";
        else
            cout << "UNLUCKY\n";
    }

    return 0;
}