//
// Created by haram on 2023-08-09
//
// Problem-Solving #1244

#include <iostream>

using namespace std;

int n, studentsNum;
bool status[101];

void solution_1(int switch_num)
{
   for(int i = 1; i <= 100; ++i)
   {
       if(i % switch_num == 0)
           status[i] = !status[i];
   }
}

void solution_2(int switch_num)
{
    status[switch_num] = !status[switch_num];
    for(int i = 1; switch_num - i >= 1 && switch_num + i <= n; ++i)
    {
       if(status[switch_num - i] == status[switch_num + i])
       {
           status[switch_num - i] = !status[switch_num - i];
           status[switch_num + i] = !status[switch_num + i];
       }
       else{
           break;
       }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> status[i];

    cin >> studentsNum;
    for(int i = 0; i < studentsNum; ++i)
    {
        int gender, switch_num;
        cin >> gender >> switch_num;
        if(gender == 1)
            solution_1(switch_num);
        else
            solution_2(switch_num);
    }

    int k = 0;
    for(int i = 1; k * 20 + i <= n; ++i){
        cout << status[k * 20 + i] << " ";
        if(i >= 20){
            i = 0;
            k++;
            cout << '\n';
        }
    }

    return 0;
}