//
// Created by haram on 2023-02-15.
//
#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str;
    getline(cin, str);

    for(auto& elem : str){
        if(elem >= 'A' && elem <= 'Z'){
            elem += 13;
            if(elem > 'Z')
                elem -= 26;
        }
        else if(elem >= 'a' && elem <= 'z'){
            int tmp = (int) elem;
            tmp += 13;
            if(tmp > 'z'){
                tmp -= 26;
            }
            elem = tmp;
        }
    }

    cout << str;


    return 0;
}