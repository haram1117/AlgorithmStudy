//
// Created by haram on 2023-08-13
//
// Problem-Solving #B
#include <iostream>

using namespace std;

string str1, str2, str3;
int a, b, c;
int result;
string val[3];
bool find(int idx, int value, string str){
    int next = value + 1;
    if(idx == 2){
        if(next % 3 == 0 && next % 5 != 0 && str == "Fizz")
            return true;
        else if(next % 3 != 0 && next % 5 == 0 && str == "Buzz")
            return true;
        else if(next % 3 == 0 && next % 5 == 0 && str == "FizzBuzz")
            return true;
        return false;
    }
    return find(idx + 1, next, val[2]);
}
int main(){
    cin >> val[0] >> val[1] >> val[2];

    if(val[0] != "Fizz" && val[0] != "Buzz" && val[0] != "FizzBuzz"){
        result = stoi(val[0]) + 3;
    }
    else if(val[1] != "Fizz" && val[1] != "Buzz" && val[1] != "FizzBuzz"){
        result = stoi(val[1]) + 2;
    }
    else if(val[2] != "Fizz" && val[2] != "Buzz" && val[2] != "FizzBuzz"){
        result = stoi(val[2]) + 1;
    }
    else{
        if(val[0] == "Fizz"){
            int i = 3;
            while(find(1, i, val[1])){
                i += 3;
            }
            result = i + 3;
        }
        else if(val[0] == "Buzz"){
            int i = 5;
            while(find(1, i, val[1])){
                i += 5;
            }
            result = i + 3;
        }
        else{
            int i = 15;
            while(find(1, i, val[1]))
                i += 15;
            result = i + 3;
        }
    }

    if(result % 3 == 0 && result % 5 != 0)
        cout << "Fizz";
    else if(result % 3 != 0 && result % 5 == 0)
        cout << "Buzz";
    else if(result % 3 == 0 && result % 5 == 0)
        cout << "FizzBuzz";
    else
        cout << result;

    return 0;
}