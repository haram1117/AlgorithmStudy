//
// Created by haram on 2023-02-01.
//
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Member{
private:
    int age;
    string name;
    int id;
public:
    Member(int __age, string __name, int __id) : age(__age), name(__name), id(__id){}

    friend bool operator < (const Member &m1, const Member &m2){
        if(m1.age < m2.age)
            return true;
        else if(m1.age > m2.age)
            return false;
        else{
            if(m1.id > m2.id)
                return false;
            else
                return true;
        }
    }

    friend bool operator > (const Member &m1, const Member &m2){
        if(m1.age > m2.age)
            return true;
        else if(m1.age < m2.age)
            return false;
        else{
            if(m1.id < m2.id)
                return false;
            else
                return true;
        }
    }

    void printInfo() const{
        cout << age << " " << name << "\n";
    }
};

int main(){
    priority_queue<Member, vector<Member>, greater<vector<Member>::value_type>> input;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int age;
        string name;
        cin >> age >> name;
        Member mem = Member(age, name, i);
        input.push(mem);
    }

    while(!input.empty()){
        input.top().printInfo();
        input.pop();
    }

    return 0;
}