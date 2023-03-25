//
// Created by haram on 2023-03-24.
//
#include <iostream>

using namespace std;
int input[100001];
int n, m;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        int tmp1;
        cin >> tmp1;
        tmp += tmp1;
        input[i] = tmp;
    }
    for(int i = 0; i < m; i++){
        int left, right;
        cin >> left >> right;
        cout << input[right] - input[left - 1] << '\n';
    }
    return 0;
}

// 5 9 12 14 15