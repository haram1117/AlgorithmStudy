//
// Created by haram on 2023-08-10
//
// Problem-Solving #20920
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<string, int> count;

class Compare{
public:
    bool operator()(const string& str1, const string & str2){
        if(count[str1] < count[str2])
            return true;
        else if(count[str1] > count[str2])
            return false;
        else{
            if(str1.length() < str2.length())
                return true;
            else if(str1.length() > str2.length())
                return false;
            else{
                if(str1 > str2)
                    return true;
                else
                    return false;
            }
        }
    }
};

int n, m;
priority_queue<string, vector<string>, Compare> pq;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        if(str.length() < m)
            continue;
        count[str]++;
    }

    for(const auto & elem : count){
        pq.emplace(elem.first);
    }

    while(!pq.empty())
    {
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}