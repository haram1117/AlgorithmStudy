//
// Created by haram on 2023-09-06
//
// Problem-Solving #1863
#include <iostream>

using namespace std;

int n;
int result;
bool info[500001];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int x, y;
    int prev = 0;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        if(prev > y){
            for(int k = prev; k > y; --k){
                if(info[k]){
                    info[k] = false;
                    result++;
                }
            }
        }
        info[y] = true;
        prev = y;
    }
    for(int k = prev; k > 0; --k){
        if(info[k])
            result++;
    }

    cout << result;

    return 0;
}