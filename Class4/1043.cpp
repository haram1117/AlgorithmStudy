//
// Created by haram on 2023-03-29.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int num;
struct person{
    bool know;
    vector<int> persons;
};
vector<person> v;
vector<vector<int>> input;
int result;
queue<int> q;
bool visited[51];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> n >> m;
    cin >> num;
    v.resize(n + 1);
    for(int i = 1; i <= num; i++){
        int tmp;
        cin >> tmp;
        v[tmp].know = true;
        q.push(tmp);
        visited[tmp] = true;
    }

    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        vector<int> v1;
        for(int j = 0; j < tmp; j++){
            int tmp2;
            cin >> tmp2;
            v1.push_back(tmp2);
        }
        for(int j = 0; j < tmp; j++){
            for(int k = 0; k < j; k++){
                v[v1[j]].persons.push_back(v1[k]);
            }
            for(int k = j + 1; k < tmp; k++){
                v[v1[j]].persons.push_back(v1[k]);
            }
        }
        input.push_back(v1);
    }

    while(!q.empty()){
        int front = q.front();
        v[front].know = true;
        q.pop();

        for(auto elem : v[front].persons){
            if(!v[elem].know && !visited[elem]){
                q.push(elem);
                visited[elem] = true;
            }
        }
    }

    for(int i = 0; i < m; i++){
        bool check = true;
        for(int j = 0; j < input[i].size(); j++){
            if(v[input[i][j]].know){
                check = false;
                break;
            }
        }
        if(check)
           result++;
    }

    cout << result;

    return 0;
}