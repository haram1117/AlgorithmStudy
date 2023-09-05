//
// Created by haram on 2023-09-05
//
// Problem-Solving #2467
#include <iostream>

using namespace std;
int n;
int info[100000];
int result = 1999999999;
pair<int, int> ans;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> info[i];

    int front = 0;
    int back = n - 1;

    while(front < back){
        int sum = info[front] + info[back];
        if(abs(sum) <= result){
            result = abs(sum);
            ans = {info[front], info[back]};
            if(sum == 0)
                break;
        }`
        if(sum > 0)
            back--;
        else
            front++;
    }

    cout << ans.first << " " << ans.second;

    return 0;
}