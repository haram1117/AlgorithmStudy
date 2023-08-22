//
// Created by haram on 2023-08-22
//
// Problem-Solving #22233
#include <iostream>
#include <unordered_set>
using namespace std;
int n, m;

unordered_set<string> set;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        set.emplace(str);
    }

    int result = n;

    for(int i = 0; i < m; ++i){
        string str;
        cin >> str;
        str += ',';
        string tmp = "";
        for(const auto & elem : str){
            if(elem == ','){
                auto it = set.find(tmp);
                if(it != set.end()){
                    set.erase(it);
                    result--;
                }
                tmp = "";
            }
            else{
                tmp += elem;
            }
        }
        cout << result << '\n';
    }

    return 0;
}