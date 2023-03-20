//
// Created by haram on 2023-03-19.
//
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string input;
    cin >> input;
    vector<string> split;

    string tmp = "";
    for(auto elem : input){
        if(elem == '-'){
            split.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += elem;
    }
    split.push_back(tmp);

    int result = 0;

    for(int i = 0; i < split.size(); i++){
        int num = 0;
        string tmp2 = "";
        for(auto character : split[i]){
            if(character == '+'){
                num += stoi(tmp2);
                tmp2 = "";
            }
            else{
                tmp2 += character;
            }
        }
        num += stoi(tmp2);
        if(i == 0)
            result += num;
        else
            result -= num;
    }
    cout << result;

    return 0;
}