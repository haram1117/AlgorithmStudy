//
// Created by haram on 2023-08-13
//
// Problem-Solving #C
#include <iostream>
#include <vector>

typedef unsigned long long ull;
using namespace std;

int n;
vector<ull> vec;
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        ull tmp;
        cin >> tmp;
        vec.emplace_back(tmp);
    }

}