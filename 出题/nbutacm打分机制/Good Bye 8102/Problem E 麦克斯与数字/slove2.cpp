#include <bits/stdc++.h>
using namespace std;
 
string s;
 
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        int p = max_element(s.begin(), s.end()) - s.begin();
        for(int i=p;i<(int)s.size();i++) cout << s[i];
        for(int i=0;i<p;i++) cout << s[i];
        cout << endl;
    }
    return 0;
}