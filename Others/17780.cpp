//
// Created by haram on 2023-06-01.
//
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 방향: 우, 좌, 상, 하
int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

struct token{
    int height;
    int direction;
    pair<int, int> location;
};

token tokens[11];
int n, k;
int info[13][13];
queue<int> board[13][13];

void swapDir(int& x){
    switch (x) {
        case 1:
            x = 2;
            break;
        case 2:
            x = 1;
            break;
        case 3:
            x = 4;
            break;
        case 4:
            x = 3;
            break;
        default:
            break;
    }
}
bool blue(int i);

bool white(int i){
    int x = tokens[i].location.first;
    int y = tokens[i].location.second;
    int newX = x + dir[tokens[i].direction][0];
    int newY = y + dir[tokens[i].direction][1];
    if(newX <= 0 || newX > n) return blue(i);
    if(newY <= 0 || newY > n) return blue(i);

    while(!board[x][y].empty()){
        board[newX][newY].emplace(board[x][y].front());
        tokens[board[x][y].front()].location.first = newX;
        tokens[board[x][y].front()].location.second = newY;
        tokens[board[x][y].front()].height = board[newX][newY].size() - 1;
        board[x][y].pop();
        if(board[newX][newY].size() >= 4)
            return false;
    }
    return true;
}

bool red(int i){
    int x = tokens[i].location.first;
    int y = tokens[i].location.second;
    int newX = x + dir[tokens[i].direction][0];
    int newY = y + dir[tokens[i].direction][1];
    if(newX <= 0 || newX > n) return blue(i);
    if(newY <= 0 || newY > n) return blue(i);

    stack<int> tmp;

    while(!board[x][y].empty()){
        tmp.emplace(board[x][y].front());
        board[x][y].pop();
    }

    while(!tmp.empty()){
        board[newX][newY].emplace(tmp.top());
        tokens[tmp.top()].location.first = newX;
        tokens[tmp.top()].location.second = newY;
        tokens[tmp.top()].height = board[newX][newY].size() - 1;
        tmp.pop();
        if(board[newX][newY].size() >= 4)
            return false;
    }
    return true;
}

bool blue(int i){
    int x = tokens[i].location.first;
    int y = tokens[i].location.second;

    swapDir(tokens[i].direction);
    int blueNewX = x + dir[tokens[i].direction][0];
    int blueNewY = y + dir[tokens[i].direction][1];

    if(info[blueNewX][blueNewY] == 0){
        return white(i);
    }
    else if(info[blueNewX][blueNewY] == 1){
        return red(i);
    }
    return true;
}

int solve(){
    int result = 0;

    while(true){
        result++;
        if(result > 1000)
            return -1;
        for(int i = 1; i <= k; ++i){
            if(tokens[i].height != 0) continue;

            int x = tokens[i].location.first;
            int y = tokens[i].location.second;
            int newX = x + dir[tokens[i].direction][0];
            int newY = y + dir[tokens[i].direction][1];
            if(newX <= 0 || newX > n) {
                if (!blue(i)) return result;
            }
            else if(newY <= 0 || newY > n) {
                if (!blue(i)) return result;
            }
            else{
                if(info[newX][newY] == 0){
                    if(!white(i)) return result;
                }
                else if(info[newX][newY] == 1){
                    if(!red(i)) return result;
                }
                else if(info[newX][newY] == 2){
                    if(!blue(i)) return result;
                }
            }
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> info[i][j];
        }
    }
    for(int i = 1; i <= k; ++i){
        cin >> tokens[i].location.first >> tokens[i].location.second >> tokens[i].direction;
        tokens[i].height = 0;
        board[tokens[i].location.first][tokens[i].location.second].emplace(i);
    }

    cout << solve();

    return 0;
}