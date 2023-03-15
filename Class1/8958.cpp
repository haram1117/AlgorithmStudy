//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;
int result;
int t;

void solve(string str){
    result = 0;
    int tmp = 0;
    for(auto elem : str){
        if(elem == 'O'){
            tmp++;
            result += tmp;
        }
        else{
            tmp = 0;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int i = 0; i < t; i++){
        string str;
        cin >> str;
        solve(str);
        cout << result << "\n";
    }

    return 0;
}