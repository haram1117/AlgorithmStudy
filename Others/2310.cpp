//
// Created by haram on 2023-06-01.
//
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;
enum roomStatus{
    Empty = 'E',
    Leprechaun = 'L',
    Troll = 'T'
};

struct room{
    roomStatus status;
    int price;
    vector<int> doors;
};

int n;
vector<room> rooms;
bool visited[1001];
bool result = false;

bool dfs(int id, int _money){
    if(id == n) return true;
    for(const auto & elem : rooms[id].doors){
        if(visited[elem]) continue;
        int nextMoney = _money;
        if(rooms[elem].status == roomStatus::Troll){
            if(rooms[elem].price > nextMoney)
                continue;
            nextMoney -= rooms[elem].price;
        }
        else if(rooms[elem].status == roomStatus::Leprechaun)
            nextMoney = max(rooms[elem].price, nextMoney);

        visited[elem] = true;
        result = dfs(elem, nextMoney);
        visited[elem] = false;
    }
    return result;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        cin >> n;
        if(n == 0)
            break;

        rooms.resize(n + 1);
        char stat;
        int price;
        for(int i = 0; i < n; ++i){
            cin >> stat >> price;
            rooms[i + 1].status = (roomStatus) stat;
            rooms[i + 1].price = price;
            int tmp;
            while(true){
                cin >> tmp;
                if(tmp == 0)
                    break;
                rooms[i + 1].doors.emplace_back(tmp);
            }
        }
        visited[1] = true;
        if(dfs(1, 0))
            cout << "Yes\n";
        else
            cout << "No\n";

        memset(visited, false, n + 1);
        result = false;
        rooms.clear();
    }

    return 0;
}