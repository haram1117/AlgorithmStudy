//
// Created by haram on 2023-01-29.
//

#include <iostream>
#include <queue>

using namespace std;

int gcd(int a, int b){
    return a % b ? gcd(b, a % b) : b;
}

int lcm(int a, int b){
    int gcdVal = gcd(a, b);
    return gcdVal * (a / gcdVal) * (b / gcdVal);
}

int main(){

    int t;
    cin >> t;

    queue<int> result;

    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;

        result.push(lcm(a, b));
    }

    while(!result.empty()){
        cout << result.front() <<"\n";
        result.pop();
    }

    return 0;
}