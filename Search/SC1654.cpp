//
// Created by haram on 2023-02-28.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, n;
vector<int> input;
int maxVal;
int result;
long long first, last, mid;
int main(){
    cin >> k >> n;
    int t;
    for(int i = 0; i < k; i++){
        cin >> t;
        input.push_back(t);
        if(maxVal < input[i])
            maxVal = input[i];
    }
    first = 1;
    last = maxVal;

    while(first <= last){
        mid = (first + last) / 2;

        int num = 0;
        for(int i = 0; i < k; i++)
            num += input[i] / mid;

        if(num >= n){
            first = mid + 1;
            if(result < mid)
                result = mid;
        }
        else
            last = mid - 1;
    }

    cout << result;

    return 0;
}