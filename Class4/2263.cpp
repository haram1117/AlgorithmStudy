//
// Created by haram on 2023-04-11.
//
#include <iostream>
using namespace std;

int n;
int post[100000];
int in[100000];

void solve(int post_start, int in_start, int num){
    int root = post[post_start + num - 1];
    cout << root << " ";
    int index;
    int num1 = 0;
    for(int i = 0; i < num; i++){
        if(in[in_start + i] == root){
            index = in_start + i + 1;
            break;
        }
        num1++;
    }
    int num2 = num - num1 - 1;
    if(num1 > 1)
        solve(post_start, in_start, num1);
    else if(num1 == 1)
        cout << in[in_start] << " ";
    if(num2 > 1)
        solve(post_start + num1, index, num2);
    else if(num2 == 1)
        cout << in[index] << " ";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }

    for(int i = 0; i < n; i++){
        cin >> post[i];
    }

    solve(0, 0, n);

    return 0;
}