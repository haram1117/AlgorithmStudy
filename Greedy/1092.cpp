//
// Created by haram on 2023-05-30.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> crane, box;

int main(){
    cin >> n;
    crane.resize(n);
    for(int i = 0; i < n; ++i) cin >> crane[i];
    cin >> m;
    box.resize(m);
    for(int i = 0; i < m; ++i) cin >> box[i];

    sort(crane.begin(), crane.end(), [](const int x, const int y) -> bool {return x > y;});
    sort(box.begin(), box.end(), [](const int x, const int y) -> bool {return x > y;});

    if(crane[0] < box[0]) {cout << -1; return 0;}

    int result = 0;
    while(!box.empty()){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < box.size(); ++j){
                if(crane[i] >= box[j]){
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
        result++;
    }
    cout << result;

    return 0;
}