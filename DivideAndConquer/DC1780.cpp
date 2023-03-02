//
// Created by haram on 2023-03-02.
//
#include <iostream>
#include <vector>

using namespace std;
int n;
int result[3];
vector<vector<int>> input;

bool checkAllSame(pair<int, int> index, int len){
    int tmp = input[index.first][index.second];
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(input[index.first + i][index.second + j] != tmp)
                return false;
        }
    }
    if(tmp == -1)
        result[0]++;
    else if(tmp == 0)
        result[1]++;
    else if(tmp == 1)
        result[2]++;

    return true;
}
void divide(pair<int, int> index, int n){
    int idx = n/3;
    if(!checkAllSame(index, n)){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                divide({index.first + idx * i, index.second + idx * j}, idx);
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
        vector<int> inputTmp;
        for(int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            inputTmp.push_back(tmp);
        }
        input.push_back(inputTmp);
    }

    divide({0, 0}, n);

    cout << result[0] << "\n" << result[1] << "\n" << result[2];
    return 0;
}