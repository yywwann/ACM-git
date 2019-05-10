#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+20;
 
int len;
string s;
long long l[N], r[N];
 
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        len = s.size();
        int count = 0;
        for(int i=0;i<len-1;i++){
            count++;
            if(s[i]=='w'&&s[i+1]=='c'){
                l[i] = count;
                count = 0;
            }
        }
        count = 0;
        for(int i=len-1;i>=1;i--){
            count++;
            if(s[i-1]=='w'&&s[i]=='c'){
                r[i] = count;
                count = 0;
            }
        }
        long long ans = 0;
        for(int i=0;i<len-1;i++){
            if(s[i]=='w'&&s[i+1]=='c'){
                ans += l[i]*r[i+1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}