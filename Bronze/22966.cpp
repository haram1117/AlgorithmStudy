//
// Created by haram on 2023-09-16
//
// Problem-Solving #22966
#include <iostream>
#include <queue>
using namespace std;

int n;
string problems[5];
int main(){
    cin >> n;
    int tmp;
    string str;
    for(int i = 0; i < n; ++i)
    {
        cin >> str >> tmp;
        problems[tmp] = str;
    }

    for(int i = 0; i < 5; ++i){
       if(problems[i] != ""){
           cout << problems[i];
           break;
       }
    }

    return 0;
}