//
// Created by haram on 2023-04-20.
//
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int n;
ll b;
int first[5][5];
vector<vector<int>> result;

vector<vector<int>> multiply(ll num) {
    vector<vector<int>> vec(n, vector<int> (n));
    vector<vector<int>> cur(n, vector<int> (n));

    if(num <= 1) {
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                cur[i][j] = first[i][j];
        }
        return cur;
    }

    if(num % 2 == 0){
        cur = multiply(num / 2);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    vec[i][j] += cur[i][k] * cur[k][j];
                }
                vec[i][j] %= 1000;
            }
        }
        return vec;
    }
    else{
        cur = multiply(num - 1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    vec[i][j] += cur[i][k] * first[k][j];
                }
                vec[i][j] %= 1000;
            }
        }
        return vec;
    }
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> b;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> first[i][j];
        }
    }

    result = multiply(b);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] % 1000 << " ";
        }
        cout << '\n';
    }

    return 0;
}