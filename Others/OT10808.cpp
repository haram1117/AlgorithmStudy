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

    for(auto elem: input){
        result[elem - 'a'] += 1;
    }

    for(int i = 0; i < 26; i++)
        cout << result[i] << " ";

    return 0;
}