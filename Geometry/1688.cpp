//
// Created by haram on 2023-05-12.
//
#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;
ll maxX;

pair<ll, ll> A;
pair<ll, ll> B;
pair<ll, ll> C;

int n;
pair<ll, ll> vertices[10001];

int ccw(pair<ll, ll> & a, pair<ll, ll> & b, pair<ll, ll>  &c){
    ll abc = (a.first * b.second + b.first * c.second + c.first * a.second)
             - (b.first * a.second + c.first * b.second + a.first * c.second);
    if(abc > 0)
        return 1;
    else if(abc == 0)
        return 0;
    return -1;
}

int intersection(pair<ll, ll> & a, pair<ll, ll> & b, pair<ll, ll> & c, pair<ll, ll> & d){
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);
    if(abc * abd < 0 && cda * cdb < 0){
        return -1;
    }
    if((abc * abd == 0 && cda * cdb < 0) || (abc * abd < 0 && cda * cdb == 0))
        return 0;
    return 1;
}

bool check(pair<ll, ll> &p1){
    int cnt = 0;
    for(int i = 0, j = 1; j <= n; ++i, ++j){
        if(p1.first == vertices[i].first && p1.second == vertices[i].second)
            return true;
        pair<ll, ll> tmp1 = make_pair(maxX + 1, p1.second + 1);
        int tmp = intersection(vertices[i], vertices[j], tmp1, p1);
        if(tmp == -1)
            cnt++;
        if(tmp == 0)
            return true;
    }
    if(cnt % 2 == 1)
        return true;
    return false;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> vertices[i].first >> vertices[i].second;
        if(vertices[i].first > maxX)
            maxX = vertices[i].first;
    }
    vertices[n].first = vertices[0].first;
    vertices[n].second = vertices[0].second;

    cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;

    cout << check(A) << '\n' << check(B) << '\n' << check(C);

    return 0;
}