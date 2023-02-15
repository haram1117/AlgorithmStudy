//
// Created by haram on 2023-02-15.
//
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
    priority_queue<string, vector<string>, greater<vector<string>::value_type>> queue1;

    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        string tmp = str.substr(i);
        queue1.push(tmp);
    }

    while(!queue1.empty()){
        cout << queue1.top() << "\n";
        queue1.pop();
    }

    return 0;
}