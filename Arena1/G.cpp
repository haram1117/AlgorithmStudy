//
// Created by haram on 2023-08-06
//
// Problem-Solving #G

#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;
const int INF = 987654321;
int n, q;
bool info[100001];
ull dp[100001];
vector<int> lq;

ull getNum(int num){
    ull result = 1;
    if(num <= 0)
        return 0;
    for(int i = 1; i <= num / 2; ++i){
        if(num % i == 0)
            result += dp[i];
    }
    dp[num] = result;
    return dp[num];
}

ull solve(int num){
    ull result = 0;

    for(int i = 1; i < 100001; ++i){
        if(i > num)
            break;
        if(!info[i])
            continue;
        if(num == i)
            result++;
        else if(num % i == 0){
            if(dp[num / i] != INF)
                result += dp[num / i];
            else
                result += getNum(num / i);
        }
    }

    return result;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        info[tmp] = true;
    }
    cin >> q;
    for(int i = 0; i < q; ++i){
        int tmp;
        cin >> tmp;
        lq.emplace_back(tmp);
    }

    for(int i = 0; i < 100001; ++i)
        dp[i] = INF;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(const auto & elem : lq){
        cout << solve(elem) << " ";
    }

    return 0;
}