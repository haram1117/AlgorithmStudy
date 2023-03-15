//
// Created by haram on 2023-03-15.
//
#include <iostream>
#include <queue>
using namespace std;
struct number{
    int num;
    int idx;
    number(int _num, int _idx) : num(_num), idx(_idx){}
    friend bool operator < (const number& other1, const number& other2){
        if(other1.num < other2.num)
            return true;
        else
            return false;
    }
    friend bool operator > (const number& other1, const number& other2){
        if(other1.num > other2.num)
            return true;
        else
            return false;
    }
};
int main(){
    priority_queue<number, vector<number>> pq;
    for(int i = 0; i < 9; i++){
        int tmp;
        cin >> tmp;
        pq.emplace(tmp, i + 1);
    }
    cout << pq.top().num << "\n";
    cout << pq.top().idx;
    return 0;
}