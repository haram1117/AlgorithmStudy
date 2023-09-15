//
// Created by haram on 2023-09-15
//
// Problem-Solving #20499
#include <iostream>

using namespace std;

int k, d, a;
int main(){
    string str;
    cin >> str;
    string tmp = "";
    int count = 0;
    for(auto const & elem : str){
        if(elem == '/'){
            if(count == 0)
                k = stoi(tmp);
            else
                d = stoi(tmp);
            tmp = "";
            count++;
        }
        else{
            tmp += elem;
        }
    }
    a = stoi(tmp);
    if(k + a < d || d == 0)
        cout << "hasu";
    else
        cout << "gosu";
    return 0;
}