//
// Created by haram on 2023-08-09
//
// Problem-Solving #17266
#include <iostream>

using namespace std;

int n, m;
int answer;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    int first;
    if(m == 1)
    {
        cin >> first;
        cout << max(first, n - first);
        return 0;
    }
    cin >> first;
    answer = first;

    int current = first;
    for(int i = 1; i < m; ++i)
    {
        int next;
        cin >> next;
        if(i == m - 1)
        {
            answer = max(answer, n - next);
            break;
        }
        answer = max(answer, (next - current + 1) / 2);
        current = next;
    }

    cout << answer;

    return 0;
}