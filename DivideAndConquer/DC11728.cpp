//
// Created by haram on 2023-03-05.
//
#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
vector<int> b;
int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        b.push_back(tmp);
    }

    auto it_a = a.begin();
    auto it_b = b.begin();

    while(it_a != a.end() && it_b != b.end()){
        if(*it_a < *it_b){
            cout << *it_a << ' ';
            it_a++;
        }
        else if(*it_a > *it_b){
            cout << *it_b << ' ';
            it_b++;
        }
        else{
            cout << *it_a << ' ' << *it_b << ' ';
            it_a++;
            it_b++;
        }
    }

    while(it_a != a.end()){
        cout << *it_a << ' ';
        it_a++;
    }
    while(it_b != b.end()){
        cout << *it_b << ' ';
        it_b++;
    }

    return 0;
}