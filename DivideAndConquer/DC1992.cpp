//
// Created by haram on 2023-03-03.
//
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> input;

bool check(pair<int, int> index, int len){
    int tmp = input[index.first][index.second];
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(input[index.first + i][index.second + j] != tmp)
                return false;
        }
    }
    return true;
}

void divide(pair<int, int> index, int len){
    if(check(index, len)){
        cout << input[index.first][index.second];
    }
    else{
        int tmpLen = len / 2;
        if(tmpLen >= 1){
            cout << "(";
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    divide({index.first + tmpLen * i, index.second + tmpLen * j}, tmpLen);
                }
            }
            cout << ")";
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        vector<int> tmpVec;
        for(int j = 0; j < n; j++){
            char tmp;
            cin >> tmp;
            tmpVec.push_back(tmp - '0');
        }
        input.push_back(tmpVec);
    }

    divide({0, 0}, n);

    return 0;
}