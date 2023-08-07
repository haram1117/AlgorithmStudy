//
// Created by haram on 2023-08-06
//
// Problem-Solving #B

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, m;
vector<string> words;
vector<string> ableWords;
map<string, bool> usedWords;
char s, e;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i){
        string tmp;
        cin >> tmp;
        words.emplace_back(tmp);
        usedWords[tmp] = true;
    }
    for(int i = 0; i < n; ++i)
        if(words[i] == "?"){
            s = i - 1 >= 0 ? words[i - 1].back() : '-';
            e = i + 1 < n ? words[i + 1].front() : '-';
        }

    cin >> m;
    for(int i = 0; i < m; ++i){
        string tmp;
        cin >> tmp;
        if(tmp[0] == s || s == '-'){
            if(tmp.back() == e || e == '-'){
                ableWords.emplace_back(tmp);
            }
        }
    }

    for(const auto & elem : ableWords){
        if(!usedWords[elem]){
            cout << elem;
            break;
        }
    }

    return 0;
}