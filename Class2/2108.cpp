//
// Created by haram on 2023-03-16.
//
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;
int n;
struct number{
    int num;
    int cnt;
    number(int _num, int _cnt) : num(_num), cnt(_cnt){}
    friend bool operator < (const number & other1, const number & other2){
        if(other1.cnt < other2.cnt)
            return true;
        else if(other1.cnt > other2.cnt)
            return false;
        else{
            if(other1.num < other2.num)
                return false;
            else
                return true;
        }
    }
};

vector<int> input;
priority_queue<number> numbers;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int maxVal = -4001;
    int minVal = 4001;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        sum += tmp;

        if(tmp > maxVal)
            maxVal = tmp;
        if(tmp < minVal)
            minVal = tmp;

        input.push_back(tmp);
    }

    sort(input.begin(), input.end());
    number tmp(input[0], 1);
    for(int i = 1; i < n; i++){
        if(tmp.num == input[i]){
            tmp.cnt++;
        }
        else{
            numbers.push(tmp);
            number tmp2(input[i], 1);
            tmp = tmp2;
        }
    }
    numbers.push(tmp);
    int result = numbers.top().num;
    int num = numbers.top().cnt;
    numbers.pop();
    if(num == numbers.top().cnt)
        result = numbers.top().num;

    int rounded = round((float)sum / n);
    if(rounded == -0)
        rounded = 0;

    cout << rounded << '\n';
    cout << input[n / 2] << '\n';
    cout << result << '\n';
    cout << maxVal - minVal << '\n';

    return 0;
}