//
// Created by haram on 2023-07-26
//
// Problem-Solving #23971

#include <iostream>

using namespace std;
int h, w, n, m;

int main(){
    cin >> h >> w >> n >> m;

    int tmp1 = w % (m + 1) == 0 ? w / (m + 1) : w / (m + 1) + 1;
    int tmp2 = h % (n + 1) == 0 ? h / (n + 1) : h / (n + 1) + 1;

    cout << tmp1 * tmp2;

    return 0;
}