//
// Created by haram on 2023-07-26
//
// Problem-Solving #10431

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tc;
int info[20];
vector<int> v;
int result;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> tc;
    for(int i = 1; i <= tc; ++i){
        cin >> i;
        for(int & k : info){
            cin >> k;
        }
        v.emplace_back(info[0]);
        for(int k = 1; k < 20; ++k){
            int num = 0;
            for(int j = k - 1; j >= 0; --j){
                if(info[k] > v[j])
                    break;
                num++;
            }
            v.emplace_back(info[k]);
            sort(v.begin(), v.end());
            result += num;
        }
        cout << i << " " << result << '\n';
        result = 0;
        v.clear();
    }
    return 0;
}