//
// Created by haram on 2023-09-19
//
// Problem-Solving #1371
#include <iostream>

using namespace std;
int cnt[26];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    while(!cin.eof()){
        getline(cin, s);
        for(auto const & elem : s){
            if(elem == ' ')
                continue;
            cnt[elem - 'a']++;
        }
    }
    int maxCount = 0;
    string ans = "";
    for(int i = 0; i < 26; ++i){
        if(maxCount < cnt[i]){
            maxCount = cnt[i];
            ans = ('a' + i);
        }
        else if(maxCount == cnt[i]){
            ans += ('a' + i);
        }
    }

    cout << ans;

    return 0;
}