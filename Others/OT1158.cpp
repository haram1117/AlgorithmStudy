//
// Created by haram on 2023-01-26.
//
#include <iostream>
#include <list>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    list<int> input;
    for(int i = 1; i <= n; i++)
        input.push_back(i);

    auto it = input.begin();
    cout << "<";
    while(!input.empty()){
        int index = 0;
        if(input.size() == n)
            index = 1;
        for(int i = index; i < k; i++){
            it++;
            if(it == input.end())
                it = input.begin();
        }
        cout << *it;
        if(input.size() != 1)
            cout << ", ";
        it = input.erase(it);
        it--;
    }
    cout << ">";


    return 0;
}