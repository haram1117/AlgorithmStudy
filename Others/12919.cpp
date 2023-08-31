//
// Created by haram on 2023-08-31
//
// Problem-Solving #12919
#include <iostream>

using namespace std;
string s, t;
int a_cnt, b_cnt;

bool solve(string str, int a, int b){
    if(str == s)
        return true;
    bool check = false;
    if(a - 1 >= a_cnt && str.back() == 'A'){
        check = solve(str.substr(0, str.size() - 1), a - 1, b);
    }
    if(check)
        return true;
    if(b - 1 >= b_cnt && str.front() == 'B'){
        string tmp = "";
        for(int i = str.size() - 1; i >= 1; --i)
            tmp += str[i];
        check = solve(tmp, a, b - 1);
    }
    return check;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s >> t;
    int a_cnt_current = 0, b_cnt_current = 0;
    for(const auto & elem : s){
        if(elem == 'A') a_cnt++;
        else    b_cnt++;
    }
    for(const auto & elem : t){
        if(elem == 'A') a_cnt_current++;
        else    b_cnt_current++;
    }

    if(solve(t, a_cnt_current, b_cnt_current))
        cout << 1;
    else
        cout << 0;

    return 0;
}