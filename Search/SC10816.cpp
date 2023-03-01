//
// Created by haram on 2023-03-01.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct dataStruct{
    int value;
    int cnt;
};

int n, m;
vector<int> input;
vector<dataStruct> datas;
int first, last, mid;
int index;
int bs(int value){
    first = 0;
    last = index;
    while(first <= last){
        mid = (first + last) / 2;

        if(datas[mid].value < value)
            first = mid + 1;
        else if(datas[mid].value > value)
            last = mid - 1;
        else{
            return datas[mid].cnt;
        }
    }
    return 0;
}
int tmp;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        input.push_back(tmp);
    }
    sort(input.begin(), input.end());

    tmp = input[0];
    datas.push_back({tmp, 1});
    for(int i = 1; i < n; i++){
        if(tmp == input[i])
            datas[index].cnt++;
        else{
            tmp = input[i];
            datas.push_back({tmp, 1});
            index++;
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        cout << bs(tmp) << " ";
    }
    return 0;
}