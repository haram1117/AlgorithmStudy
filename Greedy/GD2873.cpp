//
// Created by haram on 2023-03-08.
//
#include <iostream>

using namespace std;

int r, c;
int input[1000][1000];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> input[i][j];
        }
    }

    if(r % 2 == 0 && c % 2 == 1){
        for(int i = 0; i < c; i++){
            if(i % 2 == 0){
                for(int j = 0; j < r - 1; j++)
                    cout << "D";
            }
            else{
                for(int j = 0; j < r - 1; j++)
                    cout << "U";
            }
            if(i != c - 1)
                cout << "R";
        }
    }
    else if(r % 2 == 1){
        for(int i = 0; i < r; i++){
            if(i % 2 == 0){
                for(int j = 0; j < c - 1; j++)
                    cout << "R";
            }
            else{
                for(int j = 0; j < c - 1; j++)
                    cout << "L";
            }
            if(i != r - 1)
                cout << "D";
        }
    }
    else{
        for(int i = 0; i < r - 2; i++){
            if(i % 2 == 0){
                for(int j = 0; j < c - 1; j++)
                    cout << "R";
            }
            else{
                for(int j = 0; j < c -1 ; j++)
                    cout << "L";
            }
            cout << "D";

        }
        for(int i = 0; i < c - 2; i++){
            if(i % 2 == 0)
                cout << "D";
            else
                cout << "U";
            cout << "R";
        }
        if(input[r - 1][c - 2] < input[r - 2][c - 1]){
            cout << "RD";
        }
        else{
            cout << "DR";
        }
    }

    return 0;
}