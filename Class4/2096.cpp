//
// Created by haram on 2023-04-08.
//
#include <iostream>

using namespace std;

pair<int, int> temp[3];
int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int t1, t2, t3;

    for(int i = 0; i < n; i++){
        cin >> t1 >> t2 >> t3;
        int tmp1_1, tmp2_1, tmp3_1;
        int tmp1_2, tmp2_2, tmp3_2;
        tmp1_1 = t1 + max(temp[0].first, temp[1].first);
        tmp1_2 = t1 + min(temp[0].second, temp[1].second);

        tmp2_1 = t2 + max(temp[0].first, max(temp[1].first, temp[2].first));
        tmp2_2 = t2 + min(temp[0].second, min(temp[1].second, temp[2].second));

        tmp3_1 = t3 + max(temp[1].first, temp[2].first);
        tmp3_2 = t3 + min(temp[1].second, temp[2].second);

        temp[0] = {tmp1_1, tmp1_2};
        temp[1] = {tmp2_1, tmp2_2};
        temp[2] = {tmp3_1, tmp3_2};
    }

    cout << max(temp[0].first, max(temp[1].first, temp[2].first)) << " ";
    cout << min(temp[0].second, min(temp[1].second, temp[2].second));

    return 0;
}