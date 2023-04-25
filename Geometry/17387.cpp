//
// Created by haram on 2023-04-25.
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
    bool result = false;
    int abc = ccw(A, B, C);
    int abd = ccw(A, B, D);
    int cda = ccw(C, D, A);
    int cdb = ccw(C, D, B);
    if(abc * abd < 0 && cda * cdb < 0){
        result = true;
    }
    else if(abc * abd == 0 && cda * cdb != 0){
        if(abc == 0){
            if(min(A, B) <= C && max(A, B) >= C)
                result = true;
        }
        else{
            if(min(A, B) <= D && max(A, B) >= D)
                result = true;
        }
    }
    else if(abc * abd != 0 && cda * cdb == 0){
        if(cda == 0){
            if(min(C, D) <= A && max(C, D) >= A)
                result = true;
        }
        else{
            if(min(C, D) <= B && max(C, D) >= B)
                result = true;
        }
    }
    else if(abc * abd == 0 && cda * cdb == 0){
        if((min(A, B) <= C && max(A, B) >= C) || ( min(A, B) <= D && max(A, B) >= D)){
            result = true;
        }
        else if((min(C, D) <= A && max(C, D) >= A) || (min(C, D) <= B && max(C, D) >= B))
            result = true;
    }

    if(result)
        cout << 1;
    else
        cout << 0;

    return 0;
}