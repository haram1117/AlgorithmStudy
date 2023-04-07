//
// Created by haram on 2023-04-07.
//
#include <iostream>

using namespace std;

int input[125250];
int n;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0, index = 0; i < n; i++){
        for(int j = 0; j <= i; j++, ++index){
            cin >> input[index];
        }
    }
    int result = 0;
    input[1] = input[0] + input[1];
    input[2] = input[0] + input[2];
    result = max(max(input[0], input[1]), input[2]);
    for(int i = 2, index = 3; i < n; i++){
        for(int j = 0; j <= i; j++, ++index){
            if(j == 0){
                input[index] = input[index - i] + input[index];
            }
            else if(j == i){
                input[index] = input[index - (i + 1)] + input[index];
            }
            else{
                input[index] = max(input[index - (i + 1)], input[index - i]) + input[index];
            }
            result = max(input[index], result);
        }
    }
    cout << result;

    return 0;
}