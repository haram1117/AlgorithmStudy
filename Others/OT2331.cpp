//
// Created by haram on 2023-02-21.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <math.h>
using namespace std;

list<int> list1;
int a, p;

int main(){
    cin >> a >> p;

    list1.push_back(a);
    auto it = list1.begin();
    while(true){
        int tmp = list1.back();
        int val = 0;
        while(tmp / 10 >= 10){
            val += pow(tmp % 10, p);
            tmp /= 10;
        }
        val += pow(tmp / 10, p);
        val += pow(tmp % 10, p);
        it = find(list1.begin(), list1.end(), val);
        if(it == list1.end())
            list1.push_back(val);
        else
            break;
    }

    int result = 0;
    for(auto it2 = list1.begin(); it2 != it; it2++){
        result++;
    }
    cout << result;

    return 0;
}