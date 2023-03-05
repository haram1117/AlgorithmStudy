//
// Created by haram on 2023-03-05.
//

#include <iostream>
#include <math.h>

using namespace std;

int n;

void solve(int num, int start, int end){
    if(num == 1){
        cout << start << " " << end << '\n';
        return;
    }
    solve(num - 1, start, 6 - start - end);
    cout << start << " " << end << '\n';
    solve(num - 1, 6 - start - end, end);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    cout << (int)pow(2, n) - 1 << '\n';
    solve(n, 1, 3);

    return 0;
}