//
// Created by haram on 2023-03-15.
//
#include <iostream>
#include <map>
using namespace std;
map<char, int> map1;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    string input;
    cin >> input;

    for(auto elem : input){
        if(elem >= 'a' && elem <= 'z')
            elem += 'A' - 'a';
        map1[elem]++;
    }
    char max = ' ';
    int maxNum = 0;
    for(auto elem : map1){
        if(elem.second > maxNum){
            max = elem.first;
            maxNum = elem.second;
        }
        else if(elem.second == maxNum){
            max = ' ';
        }
    }
    if(max == ' ')
        max = '?';
    cout << max;
    return 0;
}