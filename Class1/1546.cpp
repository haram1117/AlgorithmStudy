//
// Created by haram on 2023-03-15.
//
#include <iostream>

using namespace std;
double input[1000];
int n;
double maxScore;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input[i];
        maxScore = max(maxScore, input[i]);
    }

    double sum = 0;
    for(int i = 0; i < n; i++){
        input[i] = (double) input[i] / maxScore * 100;
        sum += input[i];
    }

    cout << (double)sum / n;

    return 0;
}