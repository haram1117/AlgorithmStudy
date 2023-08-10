//
// Created by haram on 2023-08-10
//
// Problem-Solving #13305

#include <iostream>
typedef unsigned long long ull;
using namespace std;

int n;
ull length[100000];
ull price[100000];
ull answer;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n - 1; ++i)
    {
        cin >> length[i];
    }

    for(int i = 0; i < n; ++i)
    {
        cin >> price[i];
    }

    ull minPrice = price[0];
    for(int i = 1; i < n; ++i)
    {
        minPrice = min(minPrice, price[i - 1]);
        answer += length[i - 1] * minPrice;
    }

    cout << answer;

    return 0;
}