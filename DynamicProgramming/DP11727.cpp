//
// Created by haram on 2023-01-25.
//
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int first = 0;
    int second = 1;

    int result = second + 2 * first;

    for(int i = 2; i <= n; i++){
        first = second;
        second = result;

        result = (second + 2 * first) % 10007;
    }

    cout << result << endl;

    return 0;
}