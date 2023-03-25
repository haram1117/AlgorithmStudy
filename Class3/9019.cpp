//
// Created by haram on 2023-03-23.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int t;
int a, b;
queue<string> answers;

void bfs(int num){
    queue<pair<int, string>> q;
    bool visited[10000];
    fill_n(visited, 10000, false);
    visited[num] = true;
    q.emplace(num, "");

    while(!q.empty()){
        int number = q.front().first;
        string answer1 = q.front().second;
        q.pop();

        if(number == b){
            answers.emplace(answer1);
            return;
        }

        // d
        int newNum = number;
        newNum *= 2;
        newNum %= 10000;
        if(!visited[newNum]){
            q.emplace(newNum, answer1 + 'D');
            visited[newNum] = true;
        }

        // s
        newNum = number - 1;
        if(newNum < 0){
            newNum += 10000;
        }
        if(!visited[newNum]){
            q.emplace(newNum, answer1 + 'S');
            visited[newNum] = true;
        }

        string str = to_string(number);
        while(str.length() < 4)
            str = '0' + str;

        // l
        int tmp = number / 1000;
        int tmpNum = (number * 10 + tmp) % 10000;
        if(!visited[tmpNum]){
            q.emplace(tmpNum, answer1 + 'L');
            visited[tmpNum] = true;
        }

        // r
        tmp = number % 10;
        tmpNum = (number / 10) + tmp * 1000;
        if(!visited[tmpNum]){
            q.emplace(tmpNum, answer1 + 'R');
            visited[tmpNum] = true;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        bfs(a);
    }

    while(!answers.empty()){
        cout << answers.front() << '\n';
        answers.pop();
    }

    return 0;
}