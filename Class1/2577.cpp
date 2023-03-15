//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;

int a, b, c;
int result[10];
int main(){
    cin >> a >> b >> c;
    string resultStr = to_string(a * b * c);
    for(auto elem : resultStr){
        result[elem - '0']++;
    }
    for(int i = 0; i < 10; i++)
        cout << result[i] << '\n';
    return 0;
}