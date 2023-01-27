//
// Created by haram on 2023-01-26.
//
#include <iostream>
using namespace std;

int seg[(1<<18)]; // 2^18 (262,144) 크기의 배열

int init(int root, int first, int last){ // segment tree initialize
    if(first == last) { // 재귀 end
        seg[root] = 1;
        return seg[root];
    }

    int mid = (first + last) / 2;

    // 자신의 자식 노드 값의 합으로 seg[root] 채움
    seg[root] = init(2 * root, first, mid) + init(2 * root + 1, mid + 1, last);
    return seg[root];
}

int update(int root, int first, int last, int remove){
    seg[root]--;

    if(first == last) // 해당 노드면 0 return
        return 0;

    int mid = (first + last) / 2;

    if(remove <= mid)
        return update(2 * root, first, mid, remove);
    else
        return update(2 * root + 1, mid + 1, last, remove);
}

int query(int root, int first, int last, int order){
    if(first == last)
        return first;

    int mid = (first + last) / 2;

    if(order <= seg[2 * root])
        return query(2 * root, first, mid, order);
    else
        return query(2 * root + 1, mid + 1, last, order - seg[2 * root]);
}

int main(){

    int n, k;
    cin >> n >> k;

    init(1, 1, n);

    int index = 1;

    cout << "<";
    for(int i = 0; i < n; i++){
        int size = n - i; // 사람 수
        index += k - 1;

        if(index % size == 0)
            index = size;
        else if(index > size)
            index %= size;

        int num = query(1, 1, n, index);

        update(1, 1, n, num);

        if(i == n - 1)
            cout << num;
        else
            cout << num << ", ";
    }

    cout << ">";

    return 0;
}