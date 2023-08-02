//
// Created by haram on 2022-12-30.
//
#include <iostream>

using namespace std;
class A{
public:
    A(){cout << "A constructor\n";}
};
class B{
public:
    B(){cout << "B constructor\n";}
};

class C : B{
public:
    C(){cout << "C constructor\n";}
};

class D{
public:
    D():a(), b(), c(){}

private:
    B b;
    A a;
    C c;
};

int main(){
    D d;

    return 0;
}