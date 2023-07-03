//
// Created by haram on 2023-06-29.
//
#include <iostream>
#include <queue>
using namespace std;
int a, b, c;
int main(){
    cin >> a >> b >> c;

    priority_queue<int, vector<int>, greater<>> q;
    q.emplace(a);
    q.emplace(b);
    q.emplace(c);

    cout << q.top() << " ";
    q.pop();
    cout << q.top() << ' ';
    q.pop();
    cout << q.top() << ' ';
    q.pop();

    return 0;
}