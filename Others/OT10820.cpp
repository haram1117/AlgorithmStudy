//
// Created by haram on 2023-02-01.
//
#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;

    while(getline(cin, input)){
        int lower = 0;
        int upper = 0;
        int num = 0;
        int blank = 0;
        for(auto elem : input){
            if(elem >= 'a' && elem <= 'z')
                lower++;
            else if(elem >= 'A' && elem <= 'Z')
                upper++;
            else if(elem >= '0' && elem <= '9')
                num++;
            else if(elem == ' ')
                blank++;
        }
        cout << lower << " " << upper << " " << num << " " << blank << "\n";
    }
    return 0;
}