//
// Created by haram on 2023-03-07.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;


struct conference{
    int start;
    int end;

    conference(int _s, int _e) : start(_s), end(_e) {}
    friend bool operator < (const conference& other1, const conference& other2){
        if(other1.end < other2.end)
            return true;
        else if(other1.end > other2.end)
            return false;
        else{
            if(other1.start < other2.start)
                return true;
            else
                return false;
        }
    }
    friend bool operator > (const conference& other1, const conference& other2){
        if(other1.end < other2.end)
            return false;
        else if(other1.end > other2.end)
            return true;
        else{
            if(other1.start < other2.start)
                return false;
            else
                return true;
        }
    }
};

vector<conference> input;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        int s, e;
        cin >> s >> e;
        input.emplace_back(s, e);
    }

    sort(input.begin(), input.end());

    int idx = input.begin()->end;
    int cnt = 1;
    for(auto it = input.begin() + 1; it != input.end(); it++){
        if(it->start >= idx){
            cnt++;
            idx = it->end;
        }
    }
    cout << cnt;

    return 0;
}

/*
 * 1 4
 * 3 5
 * 0 6
5 7
 3 8
 5 9
 6 10
8 11
8 12
2 13
12 14
 * */