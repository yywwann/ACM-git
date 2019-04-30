#include<bits/stdc++.h>
using namespace std;
 
int t, n;
long long ans;
 
void dfs(int x,int pos){
    if(x == n){
        ans++;
        return;
    }
 
    for(int i = max(1, pos-1); i <= min(pos+1,n); i++){
        dfs(x+1,i);
    }
}
 
int main(){
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        for(int i = 1; i <= n; i++){
            dfs(1,i);
        }
        cout << ans << endl;
    }
}