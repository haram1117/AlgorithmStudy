//
// Created by haram on 2023-03-18.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m;

struct monster{
    string name;
    int id;
    friend bool operator < (const monster & other1, const monster & other2){
        if(other1.name > other2.name)
            return false;
        return true;
    }
    friend bool operator > (const monster & other1, const monster & other2){
        if(other1.name < other2.name)
            return false;
        return true;
    }
};

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    vector<monster> monsters(n);
    vector<monster> monsters_sorted(n);
    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        monsters_sorted[i].name = name;
        monsters_sorted[i].id = i + 1;
    }
    monsters = monsters_sorted;
    sort(monsters_sorted.begin(), monsters_sorted.end());

    for(int j = 0; j < m; j++){
        string tmp;
        cin >> tmp;
        if((tmp[0] >= 'A'&& tmp[0] <= 'Z') || (tmp[tmp.length() - 1] >= 'A' && tmp[tmp.length() - 1] <= 'Z')){
            int first = 0;
            int last = monsters_sorted.size() - 1;
            while(first <= last){
                int mid = (first + last) / 2;
                if(monsters_sorted[mid].name < tmp){
                    first = mid + 1;
                }
                else if(monsters_sorted[mid].name > tmp)
                    last = mid - 1;
                else{
                    cout << monsters_sorted[mid].id << '\n';
                    break;
                }
            }
        }
        else{
            int i = stoi(tmp);
            cout << monsters[i - 1].name << '\n';
        }
    }

    return 0;
}