//
// Created by haram on 2023-03-06.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int result;
int n;
int main(){
    cin >> n;
    vector<int> inputplus;
    vector<int> inputminus;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp > 0)
            inputplus.push_back(tmp);
        else
            inputminus.push_back(tmp);
    }

    sort(inputplus.begin(), inputplus.end());
    sort(inputminus.begin(), inputminus.end());


    for(auto it = inputplus.rbegin(); it != inputplus.rend(); it++){
        if(it == inputplus.rend() - 1){
            result += *it;
            break;
        }
        int tmp = *it * *(it + 1);
        if(result + *it < result + tmp){
            result += tmp;
            it++;
        }
        else{
            result += *it;
        }
    }


    for(auto it = inputminus.begin(); it != inputminus.end(); it++){
        if(it == inputminus.end() - 1){
            result += *it;
            break;
        }
        int tmp = *it * *(it + 1);
        if(result + *it < result + tmp){
            result += tmp;
            it++;
        }
        else{
            result += *it;
        }
    }

    cout << result;

    return 0;
}


// -3 -2 -2 3 4
// 12 -2 6 = 16