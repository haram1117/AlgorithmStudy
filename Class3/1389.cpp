//
// Created by haram on 2023-03-17.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct person{
    int num = 0;
    bool visited = false;
    vector<int> connected;
};

int n, m;
int result;
vector<person> persons;

int bfs(int id){
    queue<int> queue1;
    int sum = 0;

    persons[id].visited = true;
    for(auto elem : persons[id].connected){
        if(!persons[elem].visited){
            queue1.push(elem);
            persons[elem].visited = true;
            persons[elem].num = 1;
            sum += 1;
        }
    }

    while(!queue1.empty()){
        int _id = queue1.front();
        queue1.pop();

        for(auto elem : persons[_id].connected){
            if(!persons[elem].visited){
                queue1.push(elem);
                persons[elem].visited = true;
                persons[elem].num = persons[_id].num + 1;
                sum += persons[elem].num;
            }
        }
    }
    for(auto &elem : persons){
        elem.visited = false;
        elem.num = 0;
    }
    return sum;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    persons.resize(n + 1);
    for(int i = 0; i < m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        persons[tmp1].connected.push_back(tmp2);
        persons[tmp2].connected.push_back(tmp1);
    }

    int tmp = 5050;
    for(int i = 1; i <= n; i++){
        if(tmp > bfs(i)){
            tmp = bfs(i);
            result = i;
        }
    }

    cout << result;

    return 0;
}