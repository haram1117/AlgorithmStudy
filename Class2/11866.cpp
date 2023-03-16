//
// Created by haram on 2023-03-16.
//
#include <iostream>

using namespace std;
bool removed[1001];
int n, k;
int main(){
    cin >> n >> k;
    int index = 0;
    cout << "<";
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            index++;
            if(index > n){
                index = 1;
            }
            if(removed[index]){
                j--;
                continue;
            }
        }
        removed[index] = true;
        if(i != n)
            cout << index << ", ";
        else
            cout << index << ">";
    }
    return 0;
}
// 1 2 3 4 5 6 7