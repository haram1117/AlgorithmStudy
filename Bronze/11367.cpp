//
// Created by haram on 2023-07-06
//
// Problem-Solving #11367

#include <iostream>

using namespace std;
int n;
string name;
int score;

int main(){
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> name >> score;
        cout << name << ' ';
        if(score >= 97)
            cout << "A+\n";
        else if(score >= 90)
            cout << "A\n";
        else if(score >= 87)
            cout << "B+\n";
        else if(score >= 80)
            cout << "B\n";
        else if(score >= 77)
            cout << "C+\n";
        else if(score >= 70)
            cout << "C\n";
        else if(score >= 67)
            cout << "D+\n";
        else if(score >= 60)
            cout << "D\n";
        else
            cout << "F\n";
    }

    return 0;
}