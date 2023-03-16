//
// Created by haram on 2023-03-16.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<pair<int, int>, int> map1;
vector<pair<int, int>> vector1;
int n;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        int h, w;
        cin >> h >> w;
        if(map1.find({h, w}) != map1.end()){
            map1[{h, w}]++;
        }
        else
            map1[{h, w}] = 1;
        vector1.push_back({h, w});
    }
    for(auto elem : map1){
        int num = 1;
        for(auto elem2 : map1){
            if(elem.first.first < elem2.first.first && elem.first.second < elem2.first.second){
                num += elem2.second;
            }
        }
        map1[elem.first] = num;
    }
    for(auto elem : vector1){
        cout << map1[elem] << ' ';
    }
    return 0;
}