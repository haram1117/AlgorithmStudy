//
// Created by haram on 2023-02-04.
//
#include <iostream>

using namespace std;

struct node{
    int value;
    node* next;
    node* prev;
};

class queue{
private:
    node* front;
    node* end;
    int size = 0;

public:
    void push(int val){
        if(size == 0){
            node* tmp = new node;
            tmp->value = val;
            front = tmp;
            end = tmp;
            tmp->prev = nullptr;
            tmp->next = nullptr;
        }else{
            node* tmp = new node;
            tmp->value = val;
            end->next = tmp;
            tmp->prev = end;
            tmp->next = nullptr;
            end = end->next;
        }
        size++;
    }
    int pop(){
        if(size == 0)
            return -1;
        node* tmp = front;
        front = front->next;
        int value = tmp->value;
        delete tmp;
        size--;
        return value;
    }
    int getsize(){
        return size;
    }
    bool empty(){
        return size ? false : true;
    }
    int getfront(){
        if(size == 0)
            return -1;
        return front->value;
    }
    int getback(){
        if(size == 0)
            return -1;
        return end->value;
    }
};

int main(){
    int n;
    cin >> n;

    queue queue1;

    for(int i = 0; i < n; i++){
        string command;
        cin >> command;
        if(command == "push"){
            int value;
            cin >> value;
            queue1.push(value);
        }
        else if(command == "front"){
            cout << queue1.getfront() << "\n";
        }
        else if(command == "back"){
            cout << queue1.getback() << "\n";
        }
        else if(command == "size"){
            cout << queue1.getsize() << "\n";
        }
        else if(command == "empty"){
            cout << queue1.empty() << "\n";
        }
        else if(command == "pop"){
            cout << queue1.pop() << "\n";
        }
    }

    return 0;
}