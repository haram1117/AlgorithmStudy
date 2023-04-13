//
// Created by haram on 2023-04-13.
//
#include <iostream>
#define ll long long
using namespace std;

ll result;
ll n;
struct matrix{
    ll mat[2][2];
    matrix(ll _mat[2][2]){
        mat[0][0] = _mat[0][0];
        mat[0][1] = _mat[0][1];
        mat[1][0] = _mat[1][0];
        mat[1][1] = _mat[1][1];
    }
    friend matrix operator* (const matrix& other1, const matrix& other2){
        ll ans[2][2];
        ans[0][0] = ((other1.mat[0][0] * other2.mat[0][0]) % 1000000007 + (other1.mat[0][1] * other2.mat[1][0]) % 1000000007) % 1000000007;
        ans[0][1] = ((other1.mat[0][0] * other2.mat[0][1]) % 1000000007 + (other1.mat[0][1] * other2.mat[1][1]) % 1000000007) % 1000000007;

        ans[1][0] = ((other1.mat[1][0] * other2.mat[0][0]) % 1000000007 + (other1.mat[1][1] * other2.mat[1][0]) % 1000000007) % 1000000007;
        ans[1][1] = ((other1.mat[1][0] * other2.mat[0][1]) % 1000000007 + (other1.mat[1][1] * other2.mat[1][1]) % 1000000007) % 1000000007;
        return ans;
    }
    void operator= (const matrix& other){
        this->mat[0][0] = other.mat[0][0];
        this->mat[1][0] = other.mat[1][0];
        this->mat[0][1] = other.mat[0][1];
        this->mat[1][1] = other.mat[1][1];
    }
};

ll A[2][2] = {{1, 1}, {1, 0}};
matrix AMat = matrix(A);

int main(){
    cin >> n;
    ll I[2][2] = {{1, 0}, {0, 1}};
    matrix mat = matrix(I);
    while(n > 0){
        if(n % 2 == 1)
            mat = mat * AMat;
        AMat = AMat * AMat;
        n /= 2;
    }

    cout << mat.mat[0][1];

    return 0;
}