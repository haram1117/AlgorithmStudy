//
// Created by haram on 2023-05-31.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct flower{
    int month_s;
    int day_s;

    int month_e;
    int day_e;

    int day;
    flower(int s1, int s2, int e1, int e2) : month_s(s1), day_s(s2), month_e(e1), day_e(e2){
        day = 0;
        if(month_s < 3) {
            month_s = 3;
            day_s = 1;
        }
        if(month_e > 11){
            month_e = 11;
            day_e = 30;
        }
        day += month[month_s] - day_s + 1;
        for(int i = month_s + 1; i < month_e; ++i){
            day += month[i];
        }
        day += day_e;
    }
};
auto compare = [](const flower & a, const flower & b) -> bool {
    if(a.month_s < b.month_s)
        return true;
    else if(a.month_s == b.month_s)
        if(a.day_s < b.day_s) return true;
        else if(a.day_s > b.day_s) return false;
        else return a.day < b.day;
    return false;
};

vector<flower> flowers;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i){
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        flowers.emplace_back(s1, s2, e1, e2 - 1);
    }
    sort(flowers.begin(), flowers.end(), compare);

    if(!(flowers[0].month_s == 3 && flowers[0].day_s == 1)){
        cout << 0;
        return 0;
    }

    auto comp = [](const flower & a, const flower & b) -> bool{
        if(a.month_e < b.month_e)
            return true;
        else if(a.month_e == b.month_e) return a.day_e < b.day_e;
        else    return false;
    };
    priority_queue<flower, vector<flower>, decltype(comp)> pq(comp);

    int result = 0;
    pair<int, int> last = {3, 1};

    for(int i = 0; i < flowers.size(); ++i){
        if(flowers[i].month_s < last.first || (flowers[i].month_s == last.first && flowers[i].day_s <= last.second)){
            pq.emplace(flowers[i]);
        }
        else if(!pq.empty()){
            result++;
            last = {pq.top().month_e, pq.top().day_e + 1};
            i--;
            if(last.first == 11 && last.second == 31){
                cout << result;
                return 0;
            }
            while(!pq.empty()) pq.pop();
        }
        else{
            cout << 0;
            return 0;
        }
    }
    if(!pq.empty() && !(last.first == 11 && last.second == 31)){
        result++;
        last.first = pq.top().month_e;
        last.second = pq.top().day_e + 1;
    }
    if(!((last.first == 11 && last.second == 31)))
        cout << 0;
    else
        cout << result;

    return 0;
}