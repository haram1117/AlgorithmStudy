//
// Created by haram on 2023-03-01.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
int first, last, mid;
int result;

int main(){
    cin >> n >> c;
    vector<int> input(n);
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    sort(input.begin(), input.end());

    first = 1;
    last = input[n - 1] - input[0];

    while(first <= last){
        mid = (first + last) / 2;

        int cnt = 1;
        int lastIdx = 0;
        for(int i = 1; i < n; i++){
            if(input[i] - input[lastIdx] >= mid){
                cnt++;
                lastIdx = i;
            }
        }

        if(cnt >= c){
            first = mid + 1;
            result = max(result, mid);
        }
        else
            last = mid - 1;
    }

    cout << result;

    return 0;
}