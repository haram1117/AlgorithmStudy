//
// Created by haram on 2023-04-13.
//
#include <iostream>

using namespace std;

int n, m;
int input[1025][1025];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int tmp;
            cin >> tmp;
            input[i][j] = input[i - 1][j] + input[i][j - 1] + tmp - input[i - 1][j - 1];
        }
    }

    for(int i = 0; i < m; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << input[x2][y2] - input[x1 - 1][y2] - input[x2][y1 - 1] + input[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}