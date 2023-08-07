//
// Created by haram on 2023-08-06
//
// Problem-Solving #H

#include <iostream>
#include <map>
using namespace std;
int n, m, q;
map<int, int> info1;
map<int, int> info2;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> q;
    for(int i = 0; i < q; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1)
            info1[b] += c;
        else if(a == 2)
            info2[b] += c;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cout << info1[i] + info2[j] << " ";
        }
        cout << '\n';
    }

    return 0;
}