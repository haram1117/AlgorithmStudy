//
// Created by haram on 2023-09-08
//
// Problem-Solving #22251
#include <iostream>

using namespace std;
int n, k, p, x;
int info[10][10] = {{0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
                    {4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
                    {3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
                    {3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
                    {4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
                    {3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
                    {2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
                    {3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
                    {1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
                    {2, 4, 3, 1, 2, 1, 2, 3, 1, 0}};

int solve(string num, int idx, int count){
    if(idx == k){
        int number = stoi(num);
        if(number <= n && number != x && number > 0)
            return 1;
        else
            return 0;
    }
    int ans = 0;
    for(int i = 0; count + i <= p; ++i){
        for(int j = 0; j < 10; ++j){
            if(info[num[idx] - '0'][j] == i && num[idx] - '0' != j){
                string newStr = num;
                newStr[idx] = j + '0';
                ans += solve(newStr, idx + 1, count + i);
            }
        }
    }
    ans += solve(num, idx + 1, count);
    return ans;
}

int main(){
    cin >> n >> k >> p >> x;

    string num = to_string(x);
    while(num.length() < k)
        num = '0' + num;

    int result = 0;
    result = solve(num, 0, 0);

    cout << result;

    return 0;
}