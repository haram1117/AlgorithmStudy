//
// Created by haram on 2023-07-05
//
// Problem-Solving #9713

#include <iostream>

using namespace std;
int tc;
int n;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> tc;
    for(int i = 0; i < tc; ++i){
        cin >> n;
        int sum = 0;
        for(int k = 1; k <= n; k += 2)
            sum += k;
        cout << sum << '\n';
    }

    return 0;
}