//
// Created by haram on 2023-04-13.
//
#include <iostream>
#include <vector>

using namespace std;

int n, m;
const int INF = 987654321;
int result[101][101];
vector<pair<int, int>> busInfo[101];

void solve(){
    for(int i = 1; i <= n; i++){
        result[i][i] = 0;
        for(const auto & elem : busInfo[i]){
            result[i][elem.first] = min(result[i][elem.first], elem.second);
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
            }
        }
    }
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int s, e, dist;
        cin >> s >> e >> dist;
        busInfo[s].emplace_back(e, dist);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            result[i][j] = INF;

    solve();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(result[i][j] == INF)
                cout << 0 << " ";
            else
                cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}