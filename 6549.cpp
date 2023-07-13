//
// Created by haram on 2023-07-07
//
// Problem-Solving #6549

#include <iostream>
#include <stack>
typedef long long ll;

using namespace std;

ll table[100010];
int n;

ll solve(){
    ll result = 0;

    stack<int> s;
    for(int i = 0; i <= n + 1; ++i){
        while(!s.empty() && table[s.top()] > table[i]){
            int h = s.top();
            int w;
            s.pop();
            if(s.empty())
                w = i;
            else
                w = i - s.top() - 1;

            result = max(result, table[h] * w);
        }
        s.emplace(i);
    }
    s.emplace(0);
    return result;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(true){
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0; i < n; ++i)
            cin >> table[i];
        table[n] = -1;
        cout << solve() << '\n';
    }
    return 0;
}
