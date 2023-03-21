//
// Created by haram on 2023-03-21.
//
#include <iostream>

using namespace std;
int t;

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int solve(int m, int n, int x, int y){
    int result = x;
    int max = lcm(m, n);
    while(result <= max){
        if((result - y) % n == 0){
            return result;
        }
        result += m;
    }
    return -1;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    for(int i = 0; i < t; i++){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cout << solve(m, n, x, y) << '\n';
    }
    return 0;
}