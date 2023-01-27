//
// Created by haram on 2023-01-26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    for(auto elem : vec)
        cout << elem << "\n";

    return 0;
}