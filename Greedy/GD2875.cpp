//
// Created by haram on 2023-03-08.
//
#include <iostream>

using namespace std;

int n, m, k;
int result;

int main(){
    cin >> n >> m >> k;

    if(n / 2 <= m){
        result = n / 2;
    }
    else{
        result = m;
    }

    n -= result * 2;
    m -= result;

    if(n + m >= k)
        cout << result;
    else{
        k -= (n + m);
        if(k % 3 != 0)
            result -= (k / 3 + 1);
        else
            result -= k / 3;
        if(result <= 0)
            cout << 0;
        else
            cout << result;
    }
    return 0;
}