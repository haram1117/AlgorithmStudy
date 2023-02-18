//
// Created by haram on 2023-02-18.
//
#include <iostream>

using namespace std;

struct node{
    char val;
    node* left;
    node* right;
};

class tree{
private:
    node* tmp;

public:
    node* root;
    tree(){
        root = new node{'A'};
        tmp = root;
    }

    void push(char val, char leftVal, char rightVal){
        search(root, val);
        if(leftVal != '.')
            tmp->left = new node{leftVal};
        if(rightVal != '.')
            tmp->right = new node{rightVal};
    }
    void search(node* current, char val){
        if(!current)
            return;
        search(current->left, val);
        if(current->val == val){
            tmp = current;
            return;
        }
        search(current->right, val);
    }
    void preOrder(node* current){
        if(!current)
            return;
        cout << current->val;
        preOrder(current->left);
        preOrder(current->right);
    }

    void inOrder(node* current){
        if(!current)
            return;
        inOrder(current->left);
        cout << current->val;
        inOrder(current->right);
    }

    void postOrder(node* current){
        if(!current)
            return;
        postOrder(current->left);
        postOrder(current->right);
        cout << current->val;
    }

};

int main(){
    tree tree1;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        char tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;

        tree1.push(tmp1, tmp2, tmp3);
    }

    tree1.preOrder(tree1.root);
    cout << "\n";
    tree1.inOrder(tree1.root);
    cout << "\n";
    tree1.postOrder(tree1.root);
    return 0;
}