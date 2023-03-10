//
// Created by haram on 2023-03-09.
//
#include <iostream>

using namespace std;
int n, m;
bool broken[10];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        broken[tmp] = true;
    }

    if(n == 100){
        cout << 0;
        return 0;
    }

    if(m == 10){
        cout << abs(100 - n);
        return 0;
    }


    int resultNum;
    int result;
    int i = 0;
    while(true){
        string num1 = to_string((n - i));
        string num2 = to_string((n + i));
        bool check;
        if(n - i >= 0){
            check = true;
            for(int j = 0; j < num1.length(); j++){
                if(broken[num1[j] - '0'])
                    check = false;
            }
            if(check){
                result = num1.length();
                resultNum = stoi(num1);
                break;
            }
        }
        check = true;
        for(int j = 0; j < num2.length(); j++){
            if(broken[num2[j] - '0'])
                check = false;
        }
        if(check){
            result = num2.length();
            resultNum = stoi(num2);
            break;
        }
        i++;
    }

    result += abs(resultNum - n);

    if(result > abs(n - 100))
        result = abs(n - 100);

    cout << result;

    return 0;
}