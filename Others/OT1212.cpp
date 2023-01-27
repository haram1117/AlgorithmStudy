//
// Created by haram on 2023-01-27.
//

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

string input;
int main(){
    cin >> input;

    string result = "";

    if(input == "0"){
        cout << "0";
        return 0;
    }

    for(int i = 0; i < input.length(); i++){
        int tmp = input[i] - '0';
        bitset<3> bit(tmp);
        result += bit.to_string();
    }

    while(*result.begin() == '0'){
        result.erase(result.begin());
    }

    cout << result;
    return 0;
}