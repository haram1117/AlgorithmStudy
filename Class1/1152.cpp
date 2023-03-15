//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;

int result;
int main(){
    string str;
    getline(cin, str);
    for(int i = 0; i < str.length(); i++)
        if(str[i] == ' ')
            result++;
    if(str[0] == ' ')
        result--;
    if(str[str.length() - 1] == ' ')
        result--;
    cout << result + 1;
    return 0;
}