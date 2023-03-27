//
// Created by haram on 2023-03-26.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct number{
    int value;
    int index;
    number(int _value, int _index) : value(_value), index(_index){}
    friend bool operator > (const number& other1, const number& other2){
        if(other1.value > other2.value)
            return true;
        else
            return false;
    }
};

int n;
priority_queue<number, vector<number>, greater<number>> numbers;
vector<int> input;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    input.resize(n);
    for(int i = 0; i < n; i++){
        cin >> input[i];
        numbers.emplace(input[i], i);
    }

    int idx = -1;
    int tmp = numbers.top().value;
    while(!numbers.empty()){
        if(tmp == numbers.top().value && idx != -1){
            input[numbers.top().index] = idx;
            numbers.pop();
            continue;
        }
        idx++;
        tmp = numbers.top().value;
        input[numbers.top().index] = idx;
        numbers.pop();
    }

    for(int i = 0; i < input.size(); i++)
        cout << input[i] << ' ';


    return 0;
}