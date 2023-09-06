//
// Created by haram on 2023-09-06
//
// Problem-Solving #7682
#include <iostream>

using namespace std;

string str;
bool count(int& count_x, int & count_o, int& count_empty){
    for(auto const & elem : str){
        if(elem == 'X')
            count_x++;
        else if(elem == 'O')
            count_o++;
        else
            count_empty++;
    }
    int sub = count_x - count_o;
    if(sub == 0 || sub == 1)
        return true;
    return false;
}

bool check(char ch){
    if(ch == str[0] && ch == str[4] && ch == str[8])
        return true;
    if(ch == str[2] && ch == str[4] && ch == str[6])
        return true;
    for(int i = 0; i < 3; ++i){
        if(ch == str[i] && ch == str[i + 3] && ch == str[i + 6])
            return true;
        if(ch == str[i * 3] && ch == str[i * 3 + 1] && ch == str[i * 3 + 2])
            return true;
    }
    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        cin >> str;
        if(str == "end")
            break;
        int count_empty = 0;
        int count_x = 0;
        int count_o = 0;
        if(!count(count_x, count_o, count_empty)){
            cout << "invalid\n";
            continue;
        }
        bool check1 = check('O');
        bool check2 = check('X');
        if(count_empty == 0 && !check1 && !check2){
            cout << "valid\n";
            continue;
        }
        bool isValid = false;
        if(count_x == count_o)
            isValid = check1 && !check2;
        else
            isValid = check2 && !check1;
        if(isValid)
            cout << "valid\n";
        else
            cout << "invalid\n";
    }

    return 0;
}