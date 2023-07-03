//
// Created by haram on 2023-06-29.
//
#include <iostream>

using namespace std;
int a, b;
int main(){
    cin >> a >> b;

    if(a >= 3 && b <= 4)
        cout << "TroyMartian\n";
    if(a <= 6 && b >= 2)
        cout << "VladSaturnian\n";
    if(a <= 2 && b <= 3)
        cout << "GraemeMercurian\n";

    return 0;
}