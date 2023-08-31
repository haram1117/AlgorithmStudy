//
// Created by haram on 2023-08-31
//
// Problem-Solving #1522
#include <iostream>
#include <queue>

using namespace std;
string str;
int main(){
    cin >> str;
    int a_cnt = 0;
    for(const auto & elem : str)
        if(elem == 'a')
            a_cnt++;

    queue<char> q;
    int count = 0;
    for(int i = 0; i < a_cnt; ++i){
        q.emplace(str[i]);
        if(str[i] == 'b')
            count++;
    }

    int answer = count;

    for(int i = a_cnt; i < str.size() + a_cnt - 1; ++i){
        int idx = i;
        if(idx >= str.size()){
            idx -= str.size();
        }
        if(q.front() == 'b')
            count--;
        q.pop();

        if(str[idx] == 'b')
            count++;
        q.emplace(str[idx]);

        answer = min(answer, count);
    }

    cout << answer;

    return 0;
}