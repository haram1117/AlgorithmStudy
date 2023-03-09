//
// Created by haram on 2023-03-08.
//
#include <iostream>
#include <algorithm>
using namespace std;
string n;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    int num = 0;
    bool hasZero = false;
    for(int i = 0; i < n.length(); i++){
        num += n[i] - '0';
        if(n[i] == '0')
            hasZero = true;
    }
    if(num % 3 != 0){
        cout << -1;
        return 0;
    }
    if(!hasZero){
        cout << -1;
        return 0;
    }

    sort(n.begin(), n.end(), greater<char>());
    cout << n;
    return 0;
}