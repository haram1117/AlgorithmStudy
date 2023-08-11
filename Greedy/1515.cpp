//
// Created by haram on 2023-08-11
//
// Problem-Solving #1515
#include <iostream>

using namespace std;

string input;
int n;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> input;
    n = 1;
    for(int i = 0; i < input.length(); )
    {
        string str = to_string(n);
        int idx1 = 0, idx2 = 0;
        while(idx1 < str.length() && i + idx2 < input.length())
        {
            if(str[idx1] == input[i + idx2])
            {
                idx1++;
                idx2++;
            }
            else{
                idx1++;
            }
        }
        if(idx2 == 0)
        {
            n++;
        }
        else{
            n++;
            i += idx2;
        }
    }

    cout << n - 1;
    return 0;
}