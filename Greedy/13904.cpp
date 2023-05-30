//
// Created by haram on 2023-05-30.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct work{
    int due;
    int score;
    work(int _due, int _score) : due(_due), score(_score){}
};

int n;
bool day[1001];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    auto comp = [](const work & a, const work & b) -> bool{
        if(a.score < b.score)
            return true;
        else if(a.score == b.score) return a.due > b.due;
        else return false;
    };
    priority_queue<work, vector<work>, decltype(comp)> works(comp);

    for(int i = 0; i < n; ++i){
        int due, score;
        cin >> due >> score;
        works.emplace(due, score);
    }

    int score = 0;
    while(!works.empty()){
        work tmp = works.top();
        works.pop();
        for(int i = tmp.due; i > 0; --i){
            if(!day[i]){
                day[i] = true;
                score += tmp.score;
                break;
            }
        }
    }

    cout << score;
    return 0;
}