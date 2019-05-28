#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N(5005);

int n, m;
char p[N][N];
int dp[N][N];
//dp[i][j]代表从i开始长度为j的个数

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(dp,0,sizeof dp);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",p[i]+1);

        int cnt(0);
        for(int i=1;i<=n;i++){
            cnt = 0;
            for(int j=1;j<=m;j++){
                if(p[i][j]=='1'){
                    cnt++;
                    dp[j-cnt+1][cnt]++;
                }
                else{
                    cnt = 0;
                }
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] += dp[i-1][j+1];
            }
        }

        int ans(0);
        for(int i=1;i<=m;i++){//枚举起点
            for(int j=1;i+j-1<=m;j++){//枚举长度
                ans = max(ans, j*dp[i][j]);
                //O(1)得到从i开始长度为j的区间都为1的个数
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
