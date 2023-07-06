//
// Created by haram on 2023-07-06
//
// Problem-Solving #11319

#include <iostream>

using namespace std;
int tc;
string str;
int c, v;
bool check;
char vowels[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> tc;
    cin.ignore();
    for(int i = 0; i < tc; ++i){
        getline(cin, str);
        check = false;
        c = 0; v = 0;

        // 2
        for(const auto & elem : str){
            check = false;
            if(elem == ' ')
                continue;
            for(const char vowel : vowels)
                if(elem == vowel){
                    check = true;
                    break;
                }
            if(!check)
                c++;
            else
                v++;
        }
        cout << c << " " << v << '\n';
    }
    return 0;
}