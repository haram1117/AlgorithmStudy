//
// Created by haram on 2023-03-15.
//
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

struct word{
    int length;
    string str;
    word(int _length, string _str) : length(_length), str(std::move(_str)){}
    friend bool operator < (const word& other1, const word& other2){
        if(other1.length < other2.length)
            return true;
        else if(other1.length > other2.length)
            return false;
        else{
            if(other1.str < other2.str)
                return true;
            else
                return false;
        }
    }
    friend bool operator > (const word& other1, const word& other2){
        if(other1.length > other2.length)
            return true;
        else if(other1.length < other2.length)
            return false;
        else{
            if(other1.str > other2.str)
                return true;
            else
                return false;
        }
    }
};
priority_queue<word, vector<word>, greater<word>> pq;
int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        pq.emplace(tmp.length(), tmp);
    }
    string tmp;
    while(!pq.empty()){
        if(tmp != pq.top().str){
            tmp = pq.top().str;
            cout << pq.top().str << '\n';
        }
        pq.pop();
    }
    return 0;
}