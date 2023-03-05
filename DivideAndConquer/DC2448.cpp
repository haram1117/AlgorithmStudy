//
// Created by haram on 2023-03-03.
//
#include <iostream>
#include <vector>
using namespace std;
int n;
char result[3072][6144];

void divide(pair<int, int> index, int size){
    if(size == 1){
        result[index.first - 2][index.second + 2] = '*';
        result[index.first - 1][index.second + 1] = '*';
        result[index.first - 1][index.second + 3] = '*';
        for(int i = 0; i < 5; i++)
            result[index.first][index.second + i] = '*';
        return;
    }

    int len = size / 2;
    divide({index.first, index.second}, len);
    divide({index.first, index.second + 6 * len}, len);
    divide({index.first - 3 * len, index.second + 3 * len}, len);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n; j++)
            result[i][j] = ' ';
    }

    divide({n - 1, 0}, n / 3);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n; j++)
            cout << result[i][j];
        cout << '\n';
    }

    return 0;
}