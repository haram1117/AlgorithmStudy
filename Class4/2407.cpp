//
// Created by haram on 2023-04-11.
//
#include <iostream>

using namespace std;
int n, m;
long long table1[101][101], table2[101][101];

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        table1[i][0] = 1;
        for(int j = 1; j < i; j++){
            table1[i][j] = table1[i - 1][j - 1] + table1[i - 1][j];
            table2[i][j] = table2[i - 1][j - 1] + table2[i - 1][j];
            if(table1[i][j] >= 10000000000000000){
                table2[i][j]++;
                table1[i][j] -= 10000000000000000;
            }
        }
        table1[i][i] = 1;
    }
    if(table2[n][m] == 0)
        cout << table1[n][m];
    else{
        cout << table2[n][m];
        string str = to_string(table1[n][m]);
        while(str.size() != 16){
            str = '0' + str;
        }
        cout << str;
    }
    return 0;
}