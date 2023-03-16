//
// Created by haram on 2023-03-16.
//
#include <iostream>

using namespace std;
int t;
int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        int h, w, n;
        cin >> h >> w >> n;
        int n1, n2;
        n1 = (n - 1) / h + 1;
        n2 = n % h;
        if(n2 == 0)
            n2 = h;
        cout << n2 * 100 + n1  << '\n';
    }
    return 0;
}