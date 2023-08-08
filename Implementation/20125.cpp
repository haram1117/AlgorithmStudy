//
// Created by haram on 2023-08-08
//
// Problem-Solving #20125

#include <iostream>
using namespace std;

int n;
char info[1000][1000];
pair<int, int> head;
pair<int, int> heart;
bool checkHead;
int answer[4];
int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {1, 0}};
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> info[i][j];
            if(info[i][j] == '*' && !checkHead)
            {
                checkHead = true;
                head = {i, j};
            }
        }
    }

    heart = {head.first + 1, head.second};

    int k = 1;
    while(true){
        if(info[heart.first + k][heart.second] == '_')
            break;
        k++;
    }
    int legStart = heart.first + k;

    for(int i = 0; i < 2; ++i){
        int x = heart.first + dir[i][0];
        int y = heart.second + dir[i][1];
        while(info[x][y] != '_'){
            x += dir[i][0];
            y += dir[i][1];

            answer[i]++;

            if(x < 0 || x >= n || y < 0 || y >= n)
                break;
        }
    }

    while(true){
        if(legStart >= n)
            break;
        if(info[legStart][heart.second - 1] == '*')
            answer[2]++;
        if(info[legStart][heart.second + 1] == '*')
            answer[3]++;
        else if(info[legStart][heart.second + 1] == info[legStart][heart.second - 1])
            break;
        legStart++;
    }

    cout << heart.first + 1 << " " << heart.second + 1 << "\n";
    cout << answer[0] << " " << answer[1] << " " << k - 1 << " " << answer[2] << " " << answer[3];

    return 0;
}