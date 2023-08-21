//
// Created by haram on 2023-08-21
//
// Problem-Solving #19637
#include <iostream>
#include <vector>
using namespace std;

int n, m;
struct s{
    int f;
    int l;
    string str;
    s(int _f, int _l, string _str) : f(_f), l(_l), str(_str){}
};
vector<s> words;

string binary_search(int target){
    string result = "";
    int low = 0, high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(target > words[mid].f && target <= words[mid].l)
            return words[mid].str;
        else if(target <= words[mid].f)
            high = mid - 1;
        else if(target > words[mid].l)
            low = mid + 1;
    }

    return result;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    int tmp1, tmp2;
    string str;
    cin >> str >> tmp1;
    words.emplace_back(0, tmp1, str);
    tmp2 = tmp1;
    for(int i = 0; i < n - 1; ++i){
        cin >> str >> tmp1;
        words.emplace_back(tmp2, tmp1, str);
        tmp2 = tmp1;
    }

    for(int i = 0; i < m; ++i){
        cin >> tmp1;
        if(tmp1 == 0)
            cout << words[0].str << '\n';
        else
            cout << binary_search(tmp1) << '\n';
    }

    return 0;
}