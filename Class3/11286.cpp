//
// Created by haram on 2023-03-24.
//
#include <iostream>
#include <queue>
using namespace std;
struct number{
    int value;
    friend bool operator < (const number& other1, const number& other2){
        if(::abs(other1.value) < ::abs(other2.value))
            return true;
        else if(::abs(other1.value) > ::abs(other2.value))
            return false;
        else
            return other1.value < other2.value;
    }
    friend bool operator > (const number& other1, const number& other2){
        if(::abs(other1.value) < ::abs(other2.value))
            return false;
        else if(::abs(other1.value) > ::abs(other2.value))
            return true;
        else
            return other1.value > other2.value;
    }
    number(int _value) : value(_value){}
};
priority_queue<number, deque<number>, greater<number>> pq;
int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(!tmp){
            if(pq.empty())
                cout << 0 << '\n';
            else{
                cout << pq.top().value << '\n';
                pq.pop();
            }
        }
        else{
            pq.emplace(tmp);
        }
    }
    return 0;
}