//
// Created by haram on 2023-06-29.
//
#include <iostream>

using namespace std;
int a;
int main(){
    int caseNum = 0;
    while(1){
        caseNum++;
        cin >> a;
        if(a == 0)
            break;
        cout << caseNum << ". ";
        if(a % 2){
            cout << "odd ";
            a *= 3;
            a = (a + 1) / 2;
            a *= 3;
            a = a / 9;
        }
        else {
            cout << "even ";
            a *= 3;
            a = a / 2;
            a *= 3;
            a = a / 9;
        }
        cout << a << '\n';
    }
    return 0;
}