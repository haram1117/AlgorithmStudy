//
// Created by haram on 2023-09-04
//
// Problem-Solving #14719
#include <iostream>
using namespace std;

int h, w;
int result;
int info[500];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> h >> w;

    for(int i = 0; i < w; ++i){
        cin >> info[i];
    }

    for(int j = 1; j <= h; ++j){
        int count = 0;
        bool check = false;
        for(int i = 0; i < w; ++i){
            if(info[i] < j){
                if(check)
                    count++;
            }
            else{
                check = true;
                result += count;
                count = 0;
            }
        }
    }

    cout << result;

    return 0;
}