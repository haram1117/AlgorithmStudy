#include <iostream>
#include <map>
using namespace std;

int n, need;
map<string, bool> friends;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    char tmp;
    cin >> n >> tmp;
    if(tmp == 'Y')  need = 1;
    else if(tmp == 'F') need = 2;
    else    need = 3;

    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        friends[str] = true;
    }
    cout << friends.size() / need;

    return 0;
}