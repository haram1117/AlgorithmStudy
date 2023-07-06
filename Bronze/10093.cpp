//
// Created by haram on 2023-07-06
//
// Problem-Solving #10093

#include <iostream>
typedef long long ll;

using namespace std;
ll a, b;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> a >> b;

    ll tmp = max(a, b);
    a = min(a, b);
    b = tmp;
    if(b - a > 1){
        cout << b - a - 1 << '\n';
        for(ll i = a + 1; i < b; ++i)
            cout << i << " ";
    }
    else
        cout << 0;
    return 0;
}