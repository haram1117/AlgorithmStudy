//
// Created by haram on 2023-03-20.
//
#include <iostream>
#include <queue>
#define MAX 100000
#define MIN 0
using namespace std;
int n, k;
int result = 100000;
bool visited[100001];
struct point{
    int id;
    int sum;
    point(int _id, int _sum) : id(_id), sum(_sum){}
};
void solve(int val, int sum){
    queue<point> q;
    q.emplace(val, sum);
    visited[val] = true;

    while(!q.empty()){
        int _x = q.front().id;
        int _sum = q.front().sum;
        q.pop();
        if(_x == k){
            result = _sum;
            break;
        }
        if(_x + 1 <= MAX){
            if(!visited[_x + 1]){
                q.emplace(_x + 1, _sum + 1);
                visited[_x + 1] = true;
            }
        }
        if(_x - 1 >= MIN){
            if(!visited[_x - 1]){
                q.emplace(_x - 1, _sum + 1);
                visited[_x - 1] = true;
            }
        }
        if(_x * 2 <= MAX){
            if(!visited[_x * 2]){
                q.emplace(2 * _x, _sum + 1);
                visited[_x * 2] = true;
            }
        }
    }
}
int main(){
    cin >> n >> k;

    solve(n, 0);

    cout << result;
    return 0;
}