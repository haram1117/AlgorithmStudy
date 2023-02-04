//
// Created by haram on 2023-02-03.
//

#include <iostream>
#include <string>
using namespace std;

struct node{
    int value;
    node* next;
    node* prev;
};

class stack{
private:
    node* head;
    node* tail;
    int size = 0;

public:
    void push(int x){
        if(size == 0){
            node* tmp = new node;
            tmp->value = x;
            tmp->next = nullptr;
            head = tmp;
            tail = tmp;
        }
        else{
            node* tmp = new node;
            tmp->value = x;
            tmp->next = nullptr;
            tmp->prev = tail;
            tail->next = tmp;
            tail = tail->next;
        }
        size++;
    }

    bool empty(){
        return size == 0 ? true : false;
    }

    int getsize(){
        return size;
    }

    int top(){
        if(size == 0)
            return -1;
        return tail->value;
    }

    int pop(){
        if(size == 0)
            return -1;
        node* tmp = tail;
        tail = tmp->prev;
        int val = tmp->value;
        delete tmp;
        size--;
        return val;
    }
};


int main(){
    int n;
    cin >> n;

    stack stack1;
    string command;
    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == "push"){
            int val;
            cin >> val;
            stack1.push(val);
        }
        else if(command == "top"){
            cout << stack1.top() << "\n";
        }
        else if(command == "size"){
            cout << stack1.getsize() << "\n";
        }
        else if(command == "pop"){
            cout << stack1.pop() << "\n";
        }
        else if(command == "empty"){
            cout << stack1.empty() << "\n";
        }
    }


    return 0;
}