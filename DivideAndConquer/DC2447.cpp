//
// Created by haram on 2023-03-03.
//
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<char>> result;

void divide(pair<int, int> index, int size){
    int len = size / 3;
    if(len == 1){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i != 1 || j != 1)
                    result[index.first + i][index.second + j] = '*';
            }
        }
        return;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i != 1 || j != 1){
                divide({index.first + i * len, index.second + j * len}, len);
            }
        }
    }
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        vector<char> tmpVec;
        for(int j = 0; j < n; j++)
            tmpVec.push_back(' ');
        result.push_back(tmpVec);
    }

    divide({0, 0}, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << result[i][j];
        cout << "\n";
    }

    return 0;
}