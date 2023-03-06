//
// Created by haram on 2023-03-06.
//
#include <iostream>
#include <vector>

using namespace std;
int n, m;
int result;
int main(){
    cin >> n >> m;
    if(n == 1)
        result = 1;
    else if(n == 2)
        result = min(4, (m + 1) / 2);
    else if(n >= 3){
        if(m >= 6){
            result = m - 2;
        }
        else{
            result = min(4, m);
        }
    }

    cout << result;
    return 0;
}