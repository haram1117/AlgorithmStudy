//
// Created by haram on 2023-03-01.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int tmp;
vector<int> input;
vector<int> check;
int first, last, mid;

bool bs(int value){
    first = 0;
    last = n - 1;

    while(first <= last){
        mid = (first + last) / 2;

        if(input[mid] > value)
            last = mid - 1;
        else if(input[mid] < value)
            first = mid + 1;
        else
            return true;
    }
    return false;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        input.push_back(tmp);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        check.push_back(tmp);
    }

    sort(input.begin(), input.end());

    for(auto elem : check){
        cout << bs(elem) << " ";
    }


    return 0;
}