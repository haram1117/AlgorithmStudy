//
// Created by haram on 2023-03-21.
//
#include <iostream>

using namespace std;
int n;
int input[128][128];
int white = 0;
int blue = 0;
void partition(pair<int, int> _index, int _n);

void solve(pair<int, int> _index, int _n){
    if(_n == 1){
        if(input[_index.first][_index.second])
            blue++;
        else
            white++;
        return;
    }
    int tmp = input[_index.first][_index.second];
    for(int i = 0; i < _n; i++){
        for(int j = 0; j < _n; j++){
            if(tmp != input[_index.first + i][_index.second + j]){
                partition(_index, _n);
                return;
            }
        }
    }
    if(tmp)
        blue++;
    else
        white++;
}
void partition(pair<int, int> _index, int _n){
    _n /= 2;
    solve({_index.first, _index.second}, _n);
    solve({_index.first, _index.second + _n}, _n);
    solve({_index.first + _n, _index.second}, _n);
    solve({_index.first + _n, _index.second + _n}, _n);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> input[i][j];
        }
    }

    solve({0, 0}, n);

    cout << white << '\n' << blue;

    return 0;
}