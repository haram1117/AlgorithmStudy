//
// Created by haram on 2023-09-18
//
// Problem-Solving #1264
#include <iostream>

using namespace std;
string s;
int result = 0;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        getline(cin, s);
        if(s == "#")
            break;
        result = 0;
        for(auto const & elem : s){
            if(elem == 'a' || elem == 'A')
                result++;
            else if(elem == 'e' || elem == 'E')
                result++;
            else if(elem == 'i' || elem == 'I')
                result++;
            else if(elem == 'o' || elem == 'O')
                result++;
            else if(elem == 'u' || elem == 'U')
                result++;
        }
        cout << result << '\n';
    }

    return 0;
}