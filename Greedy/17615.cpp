//
// Created by haram on 2023-08-30
//
// Problem-Solving #17615
#include <iostream>

using namespace std;

pair<bool, int> front_info;
pair<bool, int> back_info;
int n;
int red, blue;
char info[500000];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> info[i];
        if(info[i] == 'R') red++;
        else    blue++;
    }
    if(red == n || blue == n){
        cout << 0;
        return 0;
    }

    front_info.first = info[0] == 'R' ? true : false;
    back_info.first = info[n - 1] == 'R' ? true : false;

    bool check = true;
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(check){
            if(info[i] == (front_info.first ? 'R' : 'B')){
                front_info.second++;
            }
            else{
                check = false;
            }
        }
        else{
            if(info[i] == (back_info.first ? 'R' : 'B')){
                cnt++;
            }
            else
                cnt = 0;
        }
    }
    back_info.second = cnt;

    int minVal = 500000;
    if(front_info.first){
        minVal = min(minVal, red - front_info.second);
        minVal = min(minVal, blue);
    }
    else{
        minVal = min(minVal, blue - front_info.second);
        minVal = min(minVal, red);
    }
    if(back_info.first){
        minVal = min(minVal, red - back_info.second);
        minVal = min(minVal, blue);
    }
    else{
        minVal = min(minVal, blue - back_info.second);
        minVal = min(minVal, red);
    }
    cout << minVal;
    return 0;
}