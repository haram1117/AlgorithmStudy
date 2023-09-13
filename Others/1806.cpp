//
// Created by haram on 2023-09-13
//
// Problem-Solving #1806
#include <iostream>

using namespace std;
int n, s;
int info[100000];
int result;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for(int i = 0; i < n; ++i)
        cin >> info[i];

    int start = 0;
    int end = 0;
    int sum = info[0];
    int count = 1;

    while(end < n){
        if(sum >= s){
            if(result == 0)
                result = count;
            else
                result = min(result, count);
            if(count == 1)
                break;
            sum -= info[start];
            start++;
            count--;
        }
        else{
            end++;
            count++;
            sum += info[end];
        }
    }
    cout << result;
    return 0;
}