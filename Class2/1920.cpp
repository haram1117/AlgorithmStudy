//
// Created by haram on 2023-03-15.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
vector<int> input;
queue<int> test;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        test.push(tmp);
    }

    sort(input.begin(), input.end());

    while(!test.empty()){
        int first, last, mid;
        first = 0;
        last = input.size() - 1;
        int num = test.front();
        test.pop();
        bool found = false;
        while(first <= last){
            mid = (first + last) / 2;
            if(input[mid] == num){
                found = true;
                break;
            }
            else if(input[mid] > num){
                last = mid - 1;
            }
            else
                first = mid + 1;
        }
        if(found)
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}