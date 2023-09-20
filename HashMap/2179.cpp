//
// Created by haram on 2023-09-20
//
// Problem-Solving #2179
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
vector<string> words;
unordered_map<string, int> map_words;
int similar(string str1, string str2){
    int sim = 0;
    for(auto it1 = str1.begin(), it2 = str2.begin(); it1 != str1.end() && it2 != str2.end(); ++it1, ++it2){
        if(*it1 == *it2)
            sim++;
        else
            break;
    }
    return sim;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i = 1; i <= n; ++i){
        string str;
        cin >> str;
        if(!map_words[str]){
            map_words[str] = i;
            words.emplace_back(str);
        }
    }
    sort(words.begin(), words.end());

    int M = 0;
    int idx1, idx2;

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(words[i] == words[j])
                continue;
            int sim = similar(words[i], words[j]);
            if(sim == 0){
                break;
            }
            if(sim > M){
                M = sim;
                idx1 = i;
                idx2 = j;
            }
            else if(sim == M){
                pair<int, int> index1 = {min(map_words[words[idx1]], map_words[words[idx2]]), max(map_words[words[idx1]], map_words[words[idx2]])};
                pair<int, int> index2 = {min(map_words[words[i]], map_words[words[j]]), max(map_words[words[i]], map_words[words[j]])};
                if(index1.first > index2.first){
                    idx1 = i;
                    idx2 = j;
                }
                else if(index1.first == index2.first){
                    if(index1.second > index2.second){
                        idx1 = i;
                        idx2 = j;
                    }
                }
            }
        }
    }
    if(map_words[words[idx1]] < map_words[words[idx2]]){
        cout << words[idx1] << '\n' << words[idx2];
    }
    else
        cout << words[idx2] << '\n' << words[idx1];

    return 0;
}