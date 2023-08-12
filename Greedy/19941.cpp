//
// Created by haram on 2023-08-12
//
// Problem-Solving #19941
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
string input;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    cin >> input;

    int result = 0;
    for(int i = 0; i < input.length(); ++i)
    {
        if(input[i] != 'P')
            continue;
        for(int j = i - k; j <= i + k; ++j)
        {
            if(j >= 0 && j < input.length() && input[j] == 'H')
            {
                input[j] = '.';
                result++;
                break;
            }
        }
    }

    cout << result;

    return 0;
}