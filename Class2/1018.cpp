//
// Created by haram on 2023-03-15.
//
#include <iostream>
using namespace std;
char input[50][50];
int n, m;
int solve(int x, int y){
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i + j) % 2 == 0){
                if(input[x + i][y + j] == 'B')
                    cnt1++;
                else
                    cnt2++;
            }
            else{
                if(input[x + i][y + j] == 'W')
                    cnt1++;
                else
                    cnt2++;
            }
        }
    }
    return min(cnt1, cnt2);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++){
            input[i][j] = tmp[j];
        }
    }
    int result = 100;
    for(int i = 0; i <= n - 8; i++){
        for(int j = 0; j <= m - 8; j++){
            result = min(result, solve(i, j));
        }
    }
    cout << result;

    return 0;
}