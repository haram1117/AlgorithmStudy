//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;
int h, m;
int main(){
    cin >> h >> m;
    h--;
    m += 15;
    if(m >= 60){
        h++;
        m -= 60;
    }
    if(h < 0)
        h += 24;
    if(h >= 24)
        h -= 24;
    cout << h << ' ' << m;
    return 0;
}