//
// Created by haram on 2023-05-18.
//
#include <iostream>
#include <vector>
using namespace std;
pair<int, int> points[100000];
bool visited[100000];
int n;

int ccw(int aIndex, int bIndex, int cIndex){
    pair<int, int> a = points[aIndex];
    pair<int, int> b = points[bIndex];
    pair<int, int> c = points[cIndex];
    int tmp = (a.first * b.second + b.first * c.second + c.first * a.second)
            - (b.first * a.second + c.first * b.second + a.first * c.second);
    if(tmp > 0) return 1;
    if(tmp == 0)    return 0;
    return -1;
}


int main(){
    cin >> n;
    int minX = 40000;
    int minY = 40000;
    for(int i = 0; i < n; ++i){
        cin >> points[i].first >> points[i].second;
    }

    return 0;
}