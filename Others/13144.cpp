//
// Created by haram on 2023-09-14
//
// Problem-Solving #13144
#include <iostream>
#include <queue>

using namespace std;
int n;
int info[100000];
bool check[100001];
unsigned long long result;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> info[i];

    int low = 0;
    int high = 0;
    while(low < n){
        while(high < n){
            if(check[info[high]])
                break;
            check[info[high]] = true;
            high++;
        }
        result += (high - low);
        check[info[low]] = false;
        low++;
    }

    cout << result;

    return 0;
}