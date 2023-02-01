//
// Created by haram on 2023-02-01.
//
#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Student{
private:
    int language;
    int english;
    int math;
    string name;

public:
    Student(int _language, int _english, int _math, string _name)
    : language(_language), english(_english), math(_math), name(_name){}

    friend bool operator > (const Student &s1, const Student &s2){
        if(s1.language < s2.language)
            return true;
        else if(s1.language > s2.language)
            return false;
        else{
            if(s1.english > s2.english)
                return true;
            else if(s1.english < s2.english)
                return false;
            else{
                if(s1.math < s2.math)
                    return true;
                else if(s1.math > s2.math)
                    return false;
                else{
                    return s1.name > s2.name;
                }
            }
        }
    }
    void printName() const{
        cout << name << "\n";
    }
};

int main(){
    priority_queue<Student, vector<Student>, greater<vector<Student>::value_type>> input;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string name;
        int language;
        int english;
        int math;
        cin >> name >> language >> english >> math;
        Student student = Student(language, english, math, name);
        input.push(student);
    }
    while(!input.empty()){
        input.top().printName();
        input.pop();
    }

    return 0;
}