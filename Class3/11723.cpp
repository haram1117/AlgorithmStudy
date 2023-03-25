//
// Created by haram on 2023-03-25.
//
#include <iostream>
#include <set>
using namespace std;
set<int> s;
set<int> allS = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
void add(int x){
    s.insert(x);
}
void remove(int x){
    s.erase(x);
}
bool check(int x){
    if(s.find(x) == s.end())
        return 0;
    return 1;
}
void toggle(int x){
    if(check(x))
        remove(x);
    else
        add(x);
}
void all(){
    s = allS;
}
void empty(){
    s.clear();
}
int m;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> m;
    for(int i = 0; i < m; i++){
        string cmd;
        int num;
        cin >> cmd;
        if(cmd == "add"){
            cin >> num;
            add(num);
        }
        else if(cmd == "remove"){
            cin >> num;
            remove(num);
        }
        else if(cmd == "check"){
            cin >> num;
            cout << check(num) << '\n';
        }
        else if(cmd == "toggle"){
            cin >> num;
            toggle(num);
        }
        else if(cmd == "all")
            all();
        else if(cmd == "empty")
            empty();
    }

    return 0;
}