//
// Created by haram on 2023-04-23.
//
#include <iostream>

using namespace std;

pair<int, int> p1;
pair<int, int> p2;
pair<int, int> p3;

int main(){
    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;
    // CCW 알고리즘 - 벡터의 외적
    pair<int, int> vec1 = make_pair(p2.first - p1.first, p2.second - p1.second);
    pair<int, int> vec2 = make_pair(p3.first - p1.first, p3.second - p1.second);

    int ans = vec1.first * vec2.second - vec1.second * vec2.first;
    if(ans > 0)
        cout << 1;
    else if(ans == 0)
        cout << 0;
    else
        cout << -1;

    return 0;
}