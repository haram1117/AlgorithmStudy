//
// Created by haram on 2023-04-21.
//
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n, m;
int startCity, endCity;
vector<pair<int, int>> city[1001];
int remember[1001];
const int INF = 987654321;
int table[1001];

void dijk(int start){
    for(int i = 1; i <= n; ++i) table[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    table[start] = 0;
    pq.emplace(0, start);
    remember[start] = -1;

    while(!pq.empty()){
        int p = pq.top().first;
        int e = pq.top().second;
        pq.pop();
        if(table[e] < p) continue; // 이미 p가 저장되어 있는 table[e]보다 크면
        for(auto const & elem : city[e]){
            if(elem.first + p >= table[elem.second]) continue; // cost가 같은 것도 continue로 넘겨야 함
            pq.emplace(p + elem.first, elem.second);
            table[elem.second] = elem.first + p;
            remember[elem.second] = e;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int s, e, p;
        cin >> s >> e >> p;
        city[s].emplace_back(p, e);
    }

    cin >> startCity >> endCity;

    dijk(startCity);

    cout << table[endCity] << '\n';

    int tmp = remember[endCity];
    stack<int> s;
    s.emplace(endCity);
    while(tmp != -1){
        s.emplace(tmp);
        tmp = remember[tmp];
    }
    cout << s.size() << '\n';
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}