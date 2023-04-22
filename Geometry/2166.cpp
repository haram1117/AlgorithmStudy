//
// Created by haram on 2023-04-22.
//
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
int n;
pair<int, int> input[10001];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> input[i].first >> input[i].second;
    }

    input[n].first = input[0].first;
    input[n].second = input[0].second;

    ll num1 = 0;
    ll num2 = 0;

    for(int i = 0; i < n; ++i){
        num1 += (ll)input[i].first * input[i + 1].second;
        num2 += (ll)input[i + 1].first * input[i].second;
    }

    cout << fixed;
    cout.precision(1);
    cout << round(((double)abs(num1 - num2) / 2) * 10) / 10;

    return 0;
}