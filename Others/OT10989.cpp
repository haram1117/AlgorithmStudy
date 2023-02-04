//
// Created by haram on 2023-02-04.
//
#include <iostream>
using namespace std;

int count[10001];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        count[tmp]++;
    }

    for(int i = 1; i < 10001; i++){
        for(int j = 0; j < count[i]; j++)
            cout << i << "\n";
    }

    return 0;
}