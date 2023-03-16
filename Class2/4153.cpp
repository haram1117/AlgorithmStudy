//
// Created by haram on 2023-03-16.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input(3);
int main(){
    while(cin){
        cin >> input[0] >> input[1] >> input[2];
        if(input[0] == 0)
            break;
        sort(input.begin(), input.end());
        if(input[0] * input[0] + input[1] * input[1] == input[2] * input[2])
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    return 0;
}