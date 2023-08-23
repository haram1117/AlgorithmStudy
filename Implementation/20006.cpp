//
// Created by haram on 2023-08-23
//
// Problem-Solving #20006
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int p, l, m;
string n;

struct room{
    int count;
    int level;
    bool end;
    priority_queue<pair<string, int>, vector<pair<string, int>>, greater<>> players;

    room(int _level) : level(_level){
        count = 0;
        end = false;
    }

    void addPlayer(int lev, string name){
        players.emplace(name, lev);
        count++;
        if(count >= m)
            end = true;
    }

    void print(){
        if(end) cout << "Started!\n";
        else    cout << "Waiting!\n";
        while(!players.empty()){
            cout << players.top().second << " " << players.top().first << '\n';
            players.pop();
        }
    }
};

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> p >> m;
    vector<room> rooms;
    for(int i = 0; i < p; ++i){
        cin >> l >> n;
        bool check = false;
        for(int j = 0; j < rooms.size(); ++j){
            if(abs(rooms[j].level - l) <= 10 && !rooms[j].end){
                rooms[j].addPlayer(l, n);
                check = true;
                break;
            }
        }
        if(!check){
            rooms.emplace_back(l);
            rooms.back().addPlayer(l, n);
        }
    }

    for(auto & elem : rooms)
        elem.print();

    return 0;
}