//
// Created by haram on 2023-08-17
//
// Problem-Solving #2607
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> letter;
int n;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    string str;
    cin >> str;
    for(const auto & elem : str){
        letter[elem]++;
    }

    int result = 0;
    for(int i = 0; i < n - 1; ++i){
        string tmp;
        cin >> tmp;
        bool check = false;
        int checkCnt = 0;
        bool isSimilar = true;
        unordered_map<char, int> tmpMap;
        for(const auto & elem : tmp){
            tmpMap[elem]++;
        }
        for(const auto & elem : tmpMap){
            if(letter[elem.first] == elem.second)
                continue;
            if(abs(letter[elem.first] - elem.second) == 1 && !check){
                checkCnt += elem.second - letter[elem.first];
                if(checkCnt >= 2){
                    isSimilar = false;
                    break;
                }
                if(checkCnt == 0)
                    check = true;
            }
            else{
                isSimilar = false;
                break;
            }
        }
        if(isSimilar){
            check = false;
            checkCnt = 0;
            isSimilar = true;
            for(const auto & elem : letter){
                if(tmpMap[elem.first] == elem.second)
                    continue;
                if(abs(tmpMap[elem.first] - elem.second) == 1 && !check){
                    checkCnt += elem.second - tmpMap[elem.first];
                    if(checkCnt >= 2){
                        isSimilar = false;
                        break;
                    }
                    if(checkCnt == 0)
                        check = true;
                }
                else{
                    isSimilar = false;
                    break;
                }
            }
            if(isSimilar){
                result++;
            }
        }
    }

    cout << result;

    return 0;
}