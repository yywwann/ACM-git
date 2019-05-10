#include<bits/stdc++.h>
using namespace std;
 
int t,n,ans;
int dp[1005][1005];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; i++) dp[1][i] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] += dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
            }
        }
        for(int i = 1; i <= n; i++){
            ans += dp[n][i];
        }
        cout << ans << endl;
    }
}