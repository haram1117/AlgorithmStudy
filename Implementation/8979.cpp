//
// Created by haram on 2023-08-03
//
// Problem-Solving #8979

#include <iostream>
#include <queue>
using namespace std;

struct country{
    int id;
    int gold;
    int silver;
    int bronze;
    country(){}
    country(int _id, int _gold, int _silver, int _bronze) : id(_id), gold(_gold), silver(_silver), bronze(_bronze){}

    friend bool operator < (const country& other1, const country& other2){
        if(other1.gold < other2.gold)
            return true;
        else if(other1.gold > other2.gold)
            return false;
        else{
            if(other1.silver < other2.silver)
                return true;
            else if(other1.silver > other2.silver)
                return false;
            else{
                if(other1.bronze < other2.bronze)
                    return true;
                else
                    return false;
            }
        }
    }

    friend bool operator ==(const country& other1, const country& other2){
        if(other1.gold == other2.gold && other1.silver == other2.silver && other1.bronze == other2.bronze)
            return true;
        return false;
    }
};
int n, k;
priority_queue<country, vector<country>, less<>> pq;
country target;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pq.emplace(a, b, c, d);
        if(a == k)
        {
            target.id = a;
            target.gold = b;
            target.silver = c;
            target.bronze = d;
        }
    }

    int result = 1;
    country tmp = pq.top();
    pq.pop();
    while(!pq.empty() && tmp.id != k){
        tmp = pq.top();
        pq.pop();
        result++;
        if(tmp == target)
            break;
    }
    cout << result;
    return 0;
}