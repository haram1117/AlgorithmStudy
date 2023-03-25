//
// Created by haram on 2023-03-23.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;
int t;
map<string, int> categories;

int result = 0;
void solve(int n){
    int mult = 1;
    for(auto elem : categories){
        mult *= (elem.second + 1);
    }
    result = mult--;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        result = 0;
        cin >> n;
        for(int k = 0; k < n; k++){
            string cloth, category;
            cin >> cloth >> category;
            if(categories[category] == 0){
                categories[category] = 1;
            }
            else{
                categories[category] += 1;
            }
        }
        solve(categories.size());
        cout << result - 1 << '\n';
        categories.clear();
    }

    return 0;
}