//
// Created by haram on 2023-02-09.
//
#include <iostream>
#include <queue>

using namespace std;

class vert{
private:
    int x;
    int y;

public:
    vert(int _x, int _y) : x(_x), y(_y){}

    friend bool operator < (const vert& other1, const vert& other2){
        if(other1.x < other2.x)
            return true;
        else if(other1.x > other2.x)
            return false;
        else{
            if(other1.y < other2.y)
                return true;
            else if(other1.y > other2.y)
                return false;
        }
    }

    friend bool operator > (const vert& other1, const vert& other2){
        if(other1.x < other2.x)
            return false;
        else if(other1.x > other2.x)
            return true;
        else{
            if(other1.y < other2.y)
                return false;
            else if(other1.y > other2.y)
                return true;
        }
    }

    void print() const{
        cout << x << " " << y;
    }

};

priority_queue<vert, vector<vert>, greater<vector<vert>::value_type>> input;
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        vert tmp(x, y);
        input.push(tmp);
    }

    while(!input.empty()){
        input.top().print();
        cout << "\n";
        input.pop();
    }

    return 0;
}