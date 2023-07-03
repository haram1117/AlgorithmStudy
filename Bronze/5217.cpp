//
// Created by haram on 2023-06-29.
//
#include <iostream>
using namespace std;
int num;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> num;
    for(int i = 0; i < num; ++i){
        int n;
        cin >> n;
        cout << "Pairs for " << n << ": ";
        for(int j = 1; j < (n+1)/2; ++j){
            if(j != n - j){
                cout << j << " " << n - j;
            }
            else{
                break;
            }
            if(j != (n + 1) / 2 - 1)
                cout << ", ";
        }
        cout << '\n';
    }
    return 0;
}