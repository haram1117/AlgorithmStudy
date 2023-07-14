//
// Created by haram on 2023-07-14
//
// Problem-Solving #1652

#include <iostream>

using namespace std;
int n;
char map[100][100];

int horizontal(){
    int result = 0;
    for(int i = 0; i < n; ++i){
        int linked = 0;
        bool check = false;
        for(int j = 0; j < n; ++j){
            if(map[j][i] == '.'){
                linked++;
                if(linked >= 2 && !check){
                    result++;
                    check = true;
                }
            }
            else{
                linked = 0;
                check = false;
            }
        }
    }
    return result;
}

int vertical(){
    int result = 0;
    for(int i = 0; i < n; ++i){
        int linked = 0;
        bool check = false;
        for(int j = 0; j < n; ++j){
            if(map[i][j] == '.'){
                linked++;
                if(linked >= 2 && !check){
                    result++;
                    check = true;
                }
            }
            else{
                linked = 0;
                check = false;
            }
        }
    }
    return result;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cin >> map[i][j];
    }

    cout << vertical() << " " << horizontal();

    return 0;
}