//
// Created by haram on 2023-01-31.
//

#include <iostream>
#include <list>
using namespace std;

int primeInfo[1000000];
bool isPrime(int n){
    if(primeInfo[n] != -1)
        return primeInfo[n];
    if(n < 2){
        primeInfo[n] = 0;
        return false;
    }
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            primeInfo[n] = 0;
            return false;
        }
    }
    primeInfo[n] = 1;
    return true;
}

void printSuccess(int n, int a, int b){
    cout << n << " = " << a << " + " << b << "\n";
}

void printFailure(){
    cout << "Goldbach's conjecture is wrong.\n";
}

int input[100000];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    fill_n(primeInfo, 1000000, -1);

    int n = 0;
    int max = 0;
    while(true){
        cin >> input[n];
        if(max < input[n])
            max = input[n];
        if(input[n] == 0)
            break;
        n++;
    }
    for(int i = 2; i < max; i++){
        isPrime(i);
    }


    for(int i = 0; i < n; i++){
        bool check = false;
        for(int k = 3; k < input[i]; k += 2){
            if(primeInfo[k] == 0)
                continue;
            if(primeInfo[input[i] - k] == 1){
                check = true;
                printSuccess(input[i], k, input[i] - k);
                break;
            }
        }
        if(!check)
            printFailure();
    }

    return 0;
}