//
// Created by haram on 2023-03-14.
//
#include <iostream>

using namespace std;
int n, m;
int input[50][50];
long long result;
long long n1, n2, n3;
void solve1(){
    int index1 = 1;
    while(index1 != m - 1){
        for(int index2 = index1 + 1; index2 <= m - 1; index2++){
            n1 = 0, n2 = 0, n3 = 0;
            for(int i = 0; i < index1; i++){
                n1 += input[0][i];
            }
            for(int i = index1; i < index2; i++){
                n2 += input[0][i];
            }
            for(int i = index2; i < m; i++)
                n3 += input[0][i];
            result = max(result, n1 * n2 * n3);
        }
        index1++;
    }
}

void solve2(){
    int index1 = 1;
    while(index1 != n - 1){
        for(int index2 = index1 + 1; index2 <= n - 1; index2++){
            n1 = 0, n2 = 0, n3 = 0;
            for(int i = 0; i < index1; i++){
                n1 += input[i][0];
            }
            for(int i = index1; i < index2; i++){
                n2 += input[i][0];
            }
            for(int i = index2; i < n; i++)
                n3 += input[i][0];
            result = max(result, n1 * n2 * n3);
        }
        index1++;
    }
}

void solve3(){
    for(int sizeX = 1; sizeX <= n; sizeX++){
        for(int sizeY = 1; sizeY <= m; sizeY++){
            n1 = 0, n2 = 0, n3 = 0;
            if(sizeX == n){
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < sizeY; j++)
                        n1 += input[i][j];
                long long tmp = 0;
                for(int i = sizeY + 1; i < m; i++){
                    for(int p = sizeY; p < i; p++){
                        for(int k = 0; k < n; k++){
                            n2 += input[k][p];
                        }
                    }
                    for(int p = i; p < m; p++){
                        for(int k = 0; k < n; k++)
                            n3 += input[k][p];
                    }
                    tmp = max(tmp, n2 * n3);
                    n2 = 0, n3 = 0;
                }
                for(int i = 1; i < n; i++){
                    for(int p = 0; p < i; p++){
                        for(int k = sizeY; k < m; k++){
                            n2 += input[p][k];
                        }
                    }
                    for(int p = i; p < n; p++){
                        for(int k = sizeY; k < m; k++)
                            n3 += input[p][k];
                    }
                    tmp = max(tmp, n2 * n3);
                    n2 = 0, n3 = 0;
                }
                result = max(result, n1 * tmp);
            }
            else if(sizeY == m){
                for(int i = 0; i < sizeX; i++)
                    for(int j = 0; j < m; j++)
                        n1 += input[i][j];

                long long tmp = 0;

                for(int i = 1; i < m; i++){
                    for(int p = 0; p < i; p++){
                        for(int k = sizeX; k < n; k++){
                            n2 += input[k][p];
                        }
                    }
                    for(int p = i; p < m; p++){
                        for(int k = sizeX; k < n; k++)
                            n3 += input[k][p];
                    }
                    tmp = max(tmp, n2 * n3);
                    n2 = 0, n3 = 0;
                }

                for(int i = sizeX + 1; i < n; i++){
                    for(int p = sizeX; p < i; p++){
                        for(int k = 0; k < m; k++){
                            n2 += input[p][k];
                        }
                    }
                    for(int p = i; p < n; p++){
                        for(int k = 0; k < m; k++)
                            n3 += input[p][k];
                    }
                    tmp = max(tmp, n2 * n3);
                    n2 = 0, n3 = 0;
                }
                result = max(result, n1 * tmp);
            }
            else{
                for(int i = 0; i < sizeX; i++)
                    for(int j = 0; j < sizeY; j++)
                        n1 += input[i][j];

                for(int i = sizeX; i < n; i++)
                    for(int j = 0; j < m; j++)
                        n2 += input[i][j];

                for(int i = 0; i < sizeX; i++)
                    for(int j = sizeY; j < m; j++)
                        n3 += input[i][j];

                long long tmp = n2 * n3;

                n2 = 0, n3 = 0;

                for(int i = sizeX; i < n; i++)
                    for(int j = 0; j < sizeY; j++)
                        n2 += input[i][j];

                for(int i = 0; i < n; i++)
                    for(int j = sizeY; j < m; j++)
                        n3 += input[i][j];

                tmp = max(tmp, n2 * n3);
                result = max(result, n1 * tmp);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    string tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        for(int j = 0; j < m; j++){
            input[i][j] = tmp[j] - '0';
        }
    }

    if(n == 1)
        solve1();
    else if(m == 1)
        solve2();
    else
        solve3();

    cout << result;

    return 0;
}