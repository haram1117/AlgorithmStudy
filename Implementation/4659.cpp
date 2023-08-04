//
// Created by haram on 2023-08-04
//
// Problem-Solving #4659

#include <iostream>

using namespace std;
string str;
bool vowelInfo[20];
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char elem){
    for(const auto & i : vowel)
        if(i == elem)
            return true;
    return false;
}

bool isAcceptable(){
    vowelInfo[0] = isVowel(str[0]);
    vowelInfo[1] = isVowel(str[1]);
    for(int i = 2; i < str.length(); ++i){
        vowelInfo[i] = isVowel(str[i]);
        if(vowelInfo[i - 2] == vowelInfo[i - 1] && vowelInfo[i - 1] == vowelInfo[i]){
            return false;
        }
    }

    for(int i = 1; i < str.length(); ++i){
        if(str[i - 1] == str[i]){
            if(str[i - 1] != 'e' && str[i - 1] != 'o')
                return false;
        }
    }

    for(int i = 0; i < str.length(); ++i){
        if(vowelInfo[i])
            break;
        if(i == str.length() - 1)
            return false;
    }
    return true;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        cin >> str;
        if(str == "end")
            break;
        if(isAcceptable())
            cout << "<" << str << ">" << " is acceptable.\n";
        else
            cout << "<" << str << ">" << " is not acceptable.\n";
    }
    return 0;
}