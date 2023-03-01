//
// Created by haram on 2023-03-01.
//
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int maxVal;
int first, last, mid;
int result;
int main(){
    cin >> n >> m;
    vector<int> input(n);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    for(int i = 0; i < n; i++){
        cin >> input[i];
        maxVal = max(maxVal, input[i]);
    }
    first = 1;
    last = maxVal;

    while(first <= last){
        mid = (first + last) / 2;

        long long cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += (input[i] - mid) > 0 ? (input[i] - mid) : 0;
        }

        if(cnt >= m){
            first = mid + 1;
            result = max(result, mid);
        }
        else
            last = mid - 1;
    }

    cout << result;

    return 0;
}