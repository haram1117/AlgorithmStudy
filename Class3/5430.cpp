//
// Created by haram on 2023-03-21.
//
#include <iostream>
#include <deque>
#include <sstream>
#include <vector>
using namespace std;

deque<int> d;
int t;
bool emptyFlag = false;
bool rev = false;

void split(string str, char character){
    stringstream ss(str);
    string tmp;
    while(getline(ss, tmp, character)){
        d.push_back(stoi(tmp));
    }
}
void reverse(){
    rev = !rev;
}
void delete_func(){
    if(rev){
        if(d.empty()){
            emptyFlag = true;
            cout << "error\n";
            return;
        }
        d.pop_back();
    }
    else{
        if(d.empty()){
            emptyFlag = true;
            cout << "error\n";
            return;
        }
        d.pop_front();
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;

    for(int i = 0; i < t; i++){
        emptyFlag = false;
        rev = false;
        string command;
        int n;
        string input;
        cin >> command >> n >> input;
        input = input.substr(1, input.length() - 2);
        split(input, ',');
        for(auto elem : command){
            if(elem == 'R')
                reverse();
            else{
                delete_func();
                if(emptyFlag)
                    break;
            }
        }
        if(emptyFlag)
            continue;
        if(rev){
            cout << "[";
            while(!d.empty()){
                if(d.size() == 1)
                    cout << d.back();
                else
                    cout << d.back() << ",";
                d.pop_back();
            }
            cout << "]\n";
        }
        else{
            cout << "[";
            while(!d.empty()){
                if(d.size() == 1)
                    cout << d.front();
                else
                    cout << d.front() << ",";
                d.pop_front();
            }
            cout << "]\n";
        }
    }

    return 0;
}