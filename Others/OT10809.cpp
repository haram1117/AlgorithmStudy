//
// Created by haram on 2023-02-01.
//
#include <iostream>
#include <string>
using namespace std;

int result[26];
int main(){
    string input;
    cin >> input;

    fill_n(result, 26, -1);

    for(int i = 0; i < input.length(); i++){
        if(result[input[i] - 'a'] == -1)
            result[input[i] - 'a'] = i;
    }
    for(auto elem: result)
        cout << elem << " ";

    return 0;
}