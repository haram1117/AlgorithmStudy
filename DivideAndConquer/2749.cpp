//
// Created by haram on 2023-07-05
//
// Problem-Solving #2749

#include <iostream>
#include <unordered_map>

typedef unsigned long long ull;

using namespace std;
const int mod = 1000000;
unordered_map<string, ull> map;

ull fib(ull num){
    if(num == 0)    return 0;
    if(num == 1)    return 1;
    if(num == 2)    return 1;
    if(!map[to_string(num / 2)]){
        map[to_string(num / 2)] = fib(num / 2);
    }
    if(!map[to_string(num / 2 - 1)]){
        map[to_string(num / 2 - 1)] = fib(num / 2 - 1);
    }
    if(!map[to_string(num / 2 + 1)]){
        map[to_string(num / 2 + 1)] = map[to_string(num / 2 - 1)] + map[to_string(num / 2)];
    }
    if(num % 2 == 0){
        return ((map[to_string(num / 2)] * map[to_string(num / 2 + 1)]) % mod + (map[to_string(num / 2 - 1)] * map[to_string(num / 2)]) % mod) % mod;
    }
    else{
        return ((map[to_string(num / 2)] * map[to_string(num / 2)]) % mod + (map[to_string(num / 2 + 1)] * map[to_string(num / 2 + 1)]) % mod) % mod;
    }
}

ull n;

int main(){
    cin >> n;
    cout << fib(n);

    return 0;
}