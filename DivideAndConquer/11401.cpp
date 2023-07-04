//
// Created by haram on 2023-07-03.
//
#include <iostream>
typedef long long ll;

using namespace std;

int n, k;
ll fac2;
const ll mod = 1000000007;

ll factorial(int num1, int num2){
    ll result = 1;
    for(int i = num2; i <= num1; ++i)
        result = (result * i) % mod;
    return result % mod;
}

ll square(int x){
    if(x == 0)  return 1;
    if(x % 2 == 1)
        return fac2 * square(x - 1) % mod;
    else{
        ll half = square(x / 2);
        return half * half % mod;
    }
}

int main(){
    cin >> n >> k;

    ll result = 1;
    ll fac1 = factorial(n, n - k + 1);
    fac2 = factorial(k, 1);

    fac2 = square(mod - 2);

    result = fac1 * fac2 % mod;

    cout << result;

    return 0;
}