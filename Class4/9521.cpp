//
// Created by haram on 2023-04-11.
//
#include <iostream>
using namespace std;


int table[1000][1000];
string str1, str2;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> str1 >> str2;

    table[0][0] = str1[0] == str2[0] ? 1 : 0;
    for(int i = 1; i < str1.size(); i++){
        if(table[i - 1][0] == 1 || str1[i] == str2[0])
            table[i][0] = 1;
    }
    for(int i = 1; i < str2.size(); i++){
        if(table[0][i - 1] == 1 || str2[i] == str1[0])
            table[0][i] = 1;
    }

    for(int i = 1; i < str1.size(); i++){
        for(int j = 1; j < str2.size(); j++){
            if(table[i][j - 1] > table[i - 1][j])
                table[i][j] = table[i][j - 1];
            else {
                table[i][j] = table[i - 1][j];

                // table[i][j]++; -> table[i][j] = table[i -1][j - 1] + 1;
                // 이 부분 고치니까 맞았음
                if(table[i][j - 1] == table[i - 1][j] && str1[i] == str2[j])
                    table[i][j] = table[i - 1][j - 1] + 1;
                // 단순히 옆에꺼에서 올리는게 아니라 각 쌍을 제외했을 때 (대각선 위 값)에서 하나 올려야 함
            }
        }
    }

    cout << table[str1.size() - 1][str2.size() - 1];

    return 0;
}