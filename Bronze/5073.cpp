//
// Created by haram on 2023-07-26
//
// Problem-Solving #5073

#include <iostream>
#include <queue>
using namespace std;
int a, b, c;
priority_queue<int, vector<int>, less<int>> pq;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0)
            break;
        pq.emplace(a);
        pq.emplace(b);
        pq.emplace(c);

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int third = pq.top();
        pq.pop();

        if(first >= second + third)
            cout << "Invalid\n";
        else if(first == second && second == third)
            cout << "Equilateral\n";
        else if(first == second || second == third)
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }
    return 0;
}