//
// Created by haram on 2023-08-11
//
// Problem-Solving #21921
#include <iostream>
#include <queue>
using namespace std;

int n, x;
queue<int> q;
int answer_value;
int answer_term;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> x;

    int idx;
    int sum = 0;
    for(idx = 0; idx < x; ++idx)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
        q.emplace(tmp);
    }

    answer_term = 1;
    answer_value = sum;

    for(int i = idx; i < n; ++i)
    {
        int tmp;
        cin >> tmp;

        int qTop = q.front();
        q.pop();
        q.emplace(tmp);
        sum += tmp - qTop;
        if(sum > answer_value) // 값, 기간 다 갱신
        {
            answer_value = sum;
            answer_term = 1;
        }
        else if(sum == answer_value){ // 기간만 갱신
            answer_term++;
        }
    }

    if(answer_value == 0)
        cout << "SAD";
    else
        cout << answer_value << '\n' << answer_term;

    return 0;
}