//
// Created by haram on 2023-03-26.
//
#include <iostream>
#include <map>
using namespace std;

map<string, string> info;
int n, m;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str1, str2;
        cin >> str1 >> str2;
        info[str1] = str2;
    }
    for(int i = 0; i < m; i++){
        string str1;
        cin >> str1;
        cout << info[str1] << '\n';
    }
    return 0;
}