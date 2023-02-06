//
// Created by haram on 2023-02-06.
//
#include <iostream>
#include <algorithm>
using namespace std;

long long input[5000000];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    sort(input, input + n);

    cout << input[k - 1];

    return 0;
}