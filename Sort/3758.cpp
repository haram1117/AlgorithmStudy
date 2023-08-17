//
// Created by haram on 2023-08-17
//
// Problem-Solving #3758
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct team{
    int total_score;
    int id;
    int scores[101];
    int last_time;
    int submitCnt;
    team(int _id) : id(_id), total_score(0), last_time(0), submitCnt(0){
        for(int i = 0; i < 101; ++i){
            scores[i] = 0;
        }
    };
    void add_score(int problem, int score, int time){
        submitCnt++;
        last_time = time;
        if(scores[problem] < score){
            total_score -= scores[problem];
            scores[problem] = score;
            total_score += score;
        }
    }
    friend bool operator > (const team & team1, const team & team2){
        if(team1.total_score > team2.total_score)
            return true;
        else if(team1.total_score < team2.total_score)
            return false;
        else{
            if(team1.submitCnt < team2.submitCnt)
                return true;
            else if(team1.submitCnt > team2.submitCnt)
                return false;
            else{
                if(team1.last_time < team2.last_time)
                    return true;
                else
                    return false;
            }
        }
    }
};

int t;
int n, k, id, m;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n >> k >> id >> m;
        vector<team> teams;
        id--;
        for(int j = 0; j < n; ++j){
            teams.emplace_back(j);
        }
        int logId, logJ, logS;
        for(int l = 0; l < m; ++l){
            cin >> logId >> logJ >> logS;
            teams[logId - 1].add_score(logJ, logS, l);
        }
        sort(teams.begin(), teams.end(), greater<>());
        for(int j = 0; j < teams.size(); ++j){
            if(teams[j].id == id)
            {
                cout << j + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}