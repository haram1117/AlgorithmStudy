//
// Created by haram on 2023-08-09
//
// Problem-Solving #9017
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int t, n;
int teams[1001];
map<int, priority_queue<int, vector<int>, greater<>>> scores;
vector<int> person;

void remove_under_six(){
    int score = 1;
    for(auto it = person.begin(); it != person.end(); ++it)
    {
        if(teams[*it] != 6){
            person.erase(it);
            --it;
        }
        else{
            scores[*it].emplace(score);
            score++;
        };
    }
}

int score(){
    int result = 987654321;
    int answer = 0;
    for(auto & pair : scores)
    {
        int tmp = 0;
        for(int i = 0; i < 4; ++i)
        {
            tmp += pair.second.top();
            pair.second.pop();
        }
        if(result > tmp)
        {
            answer = pair.first;
            result = tmp;
        }
        else if(result == tmp)
        {
            if(scores[answer].top() > scores[pair.first].top())
            {
                answer = pair.first;
            }
        }
    }
    return answer;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        cin >> n;
        for(int j = 0; j < n; ++j)
        {
            int tmp;
            cin >> tmp;
            teams[tmp]++;
            person.emplace_back(tmp);
        }
        remove_under_six();
        cout << score() << '\n';
        for(int j = 0; j < 1001; ++j)
            teams[j] = 0;
        scores.clear();
        person.clear();
    }
}