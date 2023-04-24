//
// Created by haram on 2023-04-24.
//
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
pair<ll, ll> A;
pair<ll, ll> B;
pair<ll, ll> C;
pair<ll, ll> D;

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3){

    ll val = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
    if(val > 0)
        return 1;
    else if(val == 0)
        return 0;
    return -1;
}

int main(){
    cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second >> D.first >> D.second;

    if(ccw(A, B, C) * ccw(A, B, D) < 0){
        if(ccw(C, D, A) * ccw(C, D, B) < 0){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}