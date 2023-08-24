//
// Created by haram on 2023-08-24
//
// Problem-Solving #2304
#include <iostream>

using namespace std;
int n, l, h;
int graph[1001];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int maxVal = 0;
    int maxIdx = 0;
    for(int i = 0; i < n; ++i){
        cin >> l >> h;
        graph[l] = h;
        if(maxVal <= h){
            maxVal = h;
            maxIdx = l;
        }

    }

    int maxTmp = 0;
    int result = 0;
    for(int i = 1; i <= maxIdx; ++i){
        if(graph[i] > maxTmp){
            maxTmp = graph[i];
        }
        result += maxTmp;
    }


    for(int i = maxIdx + 1; i <= 1000; ++i){
        maxTmp = 0;
        int maxIdx2 = 0;
        for(int j = i; j <= 1000; ++j){
            if(maxTmp <= graph[j]){
                maxTmp = graph[j];
                maxIdx2 = j;
            }
        }
        result += maxTmp * (maxIdx2 - i + 1);
        i = maxIdx2;
    }

    cout << result;

    return 0;
}