//
// Created by haram on 2023-09-05
//
// Problem-Solving #2138
#include <iostream>

using namespace std;

int n;
string input, output;
int result = 987654321;

bool solve(string str, int count, int num){
    while(num < n - 1){
        if(str[num] != output[num]){
            count++;
            for(int i = 0; i < 3; ++i){
                int idx = num + i;
                if(idx < n){
                    str[idx] = (str[idx] == '0' ? '1' : '0');
                }
            }
        }
        num++;
    }
    if(str[n - 1] == output[n - 1]){
        result = min(result, count);
        return true;
    }
    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> input >> output;
    if(input == output){
        cout << 0;
        return 0;
    }
    bool check = false;
    if(input[0] == output[0]){
        string newStr = input;
        if(solve(newStr, 0, 1))
            check = true;
        newStr[2] = (newStr[2] == '0' ? '1' : '0');
        if(solve(newStr, 2, 1))
            check = true;
    }
    else{
        string newStr = input;
        newStr[0] = (newStr[0] == '0' ? '1' : '0');
        newStr[1] = (newStr[1] == '0' ? '1' : '0');
        if(solve(newStr, 1, 1))
            check = true;


        string newStr2 = input;
        newStr2[0] = (newStr2[0] == '0' ? '1' : '0');
        newStr2[1] = (newStr2[1] == '0' ? '1' : '0');
        newStr2[2] = (newStr2[2] == '0' ? '1' : '0');
        if(solve(newStr2, 1, 1))
            check = true;
    }

    if(check)
        cout << result;
    else
        cout << -1;

    return 0;
}