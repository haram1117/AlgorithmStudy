//
// Created by haram on 2023-01-29.
//

#include <iostream>

using namespace std;

long long five(int val){
    long long fiveNum = 0;
    for(long long i = 5; i <= val; i *= 5)
        fiveNum += val / i;
    return fiveNum;
}

long long two(int val){
    long long twoNum = 0;
    for(long long i = 2; i <= val; i *= 2)
        twoNum += val / i;
    return twoNum;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    long long fiveNum = five(n) - five(m) - five(n - m);
    long long twoNum = two(n) - two(m) - two(n - m);


    if(fiveNum <= 0 || twoNum <= 0){
        cout << 0;
        return 0;
    }
    cout << min(fiveNum, twoNum);

    return 0;
}