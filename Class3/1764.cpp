//
// Created by haram on 2023-03-20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int n, m;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<string> vector1;
    vector<string> vector2;
    string tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        vector1.push_back(tmp);
    }
    for(int i = 0; i < m; i++){
        cin >> tmp;
        vector2.push_back(tmp);
    }
    sort(vector1.begin(), vector1.end());
    sort(vector2.begin(), vector2.end());

    vector<string> results;
    set_intersection(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), back_inserter(results));

    cout << results.size() << '\n';
    for(auto elem : results)
        cout << elem << '\n';

    return 0;
}