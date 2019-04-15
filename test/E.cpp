// #include<cstdio>
// #include<cmath>
// #include<cstring>
// #include<string>
// #include<stack>
// #include<map>
// #include<set>
// #include<queue>
// #include<vector>
// #include<iostream>
// #include<algorithm>
// using namespace std;        //    ____   _   _  __   __
// #define ll long long       //    / ___| | |_| | \ \ / /
// const ll INF = 0x3f3f3f3f;//    | |     |  _  |  \ V /
// const ll N   = 1e5+5;    //     | |___  | | | |   | |
// const ll MOD = 1e9+7;   //       \____| |_| |_|   |_|
// ll read() {
//   ll x=0,f=1;char ch=getchar();
//   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//   while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
//   return x*f;
// }
//
//
// int main(){
//   for (int _ = read(); _; _--) {
//
//   }
//   return 0;
// }

#include <cstdio>
#include <iostream>
using namespace std;

const int INF=2e9;
const int SIZE=(1<<20);

int d[20][20];
int dp[SIZE][20];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    scanf("%d", &d[i][j]);

    for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    d[i][j]= min(d[i][j],d[i][k]+d[k][j]);

    for(int i=0;i<SIZE;++i)
    for(int j=0;j<n;++j)
    dp[i][j]=INF;

    dp[1][0]=0;
    for(int k=1;k<SIZE;++k)
    for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
    dp[k|(1<<i)|(1<<j)][i]= min(dp[k|(1<<i)|(1<<j)][i],d[j][i]+dp[k|(1<<j)][j]);

    int ans=INF;
    int tt=(1<<n)-1;
    for(int i=0;i<n;i++)
    if(ans>dp[tt][i]+d[i][0]) ans=dp[tt][i]+d[i][0];

    printf("%d\n",ans);

    return 0;
}
