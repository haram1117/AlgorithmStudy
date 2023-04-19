//
// Created by haram on 2023-04-19.
//
#include <iostream>

using namespace std;
int input[10000];
int n;
void func(int start, int end){
    if(start >= end)
        return;
    if(start == end - 1){
        cout << input[start] << '\n';
        return;
    }
    int idx = start + 1;
    while(idx < end){
        if(input[start] < input[idx])
            break;
        idx++;
    }
    func(start + 1, idx);
    func(idx, end);
    cout << input[start] << '\n';
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int tmp;
    while(cin >> tmp){
        input[n] = tmp;
        n++;
    }
    func(0, n);

    return 0;
}