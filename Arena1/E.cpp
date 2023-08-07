//
// Created by haram on 2023-08-06
//
// Problem-Solving #E

#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

const int mod = 1000000007;
int n, k;
map<ull, bool> info;
ull max1, max2;
ull maxSum;
ull square[100000];

void calculate(){
    square[0] = 1;
    square[1] = 2;
    for(int i = 2; i <= n; ++i){
        square[i] = (square[i - 1] * 2) % mod;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        ull tmp;
        cin >> tmp;
        info[tmp] = true;
        if(max1 < tmp && max2 < tmp)
        {
            max1 = tmp;
            max2 = max1;
        }
        else if(max1 > tmp && max2 < tmp){
            max2 = tmp;
        }
    }
    maxSum = (max1 + max2) % mod;
    calculate();

    int cnt = 0;
    for(ull i = k; i <= maxSum; i += k){
        for(ull j = 1; j < i / 2; ++j){
            if(!info[j])
                continue;
            if(!info[i - j])
                continue;
            cnt++;
        }
    }

    ull tmp = square[n - 2];
    ull tmp2 = square[n - 2 * cnt];
    ull result = ((tmp * 4) % mod - (cnt * tmp) % mod + tmp2) % mod - (n + 1);

    cout << result;

    return 0;
}