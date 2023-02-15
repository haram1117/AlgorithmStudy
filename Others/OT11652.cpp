//
// Created by haram on 2023-02-10.
//

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<long long, int> map1;

    int maxCount;
    long long maxNum;
    for(int i = 0; i < n; i++){
        long long tmp;
        cin >> tmp;

        if(i == 0){
            maxCount = 1;
            maxNum = tmp;
        }

        if(map1.find(tmp) != map1.end()){
            map1[tmp]++;
            if(map1[tmp] > maxCount){
                maxCount = map1[tmp];
                maxNum = tmp;
            }
            else if(map1[tmp] == maxCount && tmp < maxNum){
                maxCount = map1[tmp];
                maxNum = tmp;
            }
        }
        else{
            map1.insert({tmp, 1});
            if(maxCount == 1){
                if(maxNum > tmp)
                    maxNum = tmp;
            }
        }

    }

    cout << maxNum << "\n";

    return 0;
}