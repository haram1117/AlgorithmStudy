//
// Created by haram on 2023-01-31.
//

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    return a % b ? gcd(b, a % b) : b;
}
int main(){
    int t;
    cin >> t;
    vector<vector<int>> input(t);
    for(int i = 0; i < t; i++){
        int num;
        cin >> num;
        for(int k = 0; k < num; k++){
            int tmp;
            cin >> tmp;
            input[i].push_back(tmp);
        }
    }

    vector<long long> result(t);
    for(int i = 0; i < t; i++){
        result[i] = 0;
        for(int j = 0; j < input[i].size(); j++){
            for(int k = j + 1; k < input[i].size(); k++){
                int gcdVal = gcd(input[i][j], input[i][k]);
                result[i] += gcdVal;
            }
        }
    }

    for (auto elem : result) {
        cout << elem << "\n";
    }

    return 0;
}