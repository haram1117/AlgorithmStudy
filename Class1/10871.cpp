//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;
int n, x;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp < x)
            cout << tmp << " ";
    }
    return 0;
}