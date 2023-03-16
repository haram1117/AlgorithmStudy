//
// Created by haram on 2023-03-16.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> input;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    sort(input.begin(), input.end());

    int result = 0;
    for(auto it1 = input.begin(); it1 != input.end() - 2; it1++){
        for(auto it2 = it1 + 1; it2 != input.end() - 1; it2++){
            for(auto it3 = it2 + 1; it3 != input.end(); it3++){
                if(*it1 + *it2 + *it3 <= m){
                    result = max(result, *it1 + *it2 + *it3);
                }
            }
        }
    }

    cout << result;

    return 0;
}