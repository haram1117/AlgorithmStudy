//
// Created by haram on 2023-08-17.
//
#include <iostream>

using namespace std;

string s;
int zero, one;
int main(){
    cin >> s;

    for(const auto & elem : s){
        if(elem == '0') zero++;
        else    one++;
    }

    int tmp0 = 0;
    int tmp1 = 0;
    for(auto it = s.begin(); it != s.end(); ++it){
        if(*it == '1'){
            tmp1++;
            s.erase(it);
            --it;
            if(tmp1 * 2 == one)
                break;
        }
    }

    for(auto it = s.rbegin(); it != s.rend(); ++it){
        if(*it == '0'){
            tmp0++;
            s.erase(--it.base());
            if(tmp0 * 2 == zero)
                break;
        }
    }

    cout << s;

    return 0;
}