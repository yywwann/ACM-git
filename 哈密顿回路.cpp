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
// int n, ans;
// int pic[30][30];
// int vis[30];
// struct node {
//   int f, t, c;
//   node(int f, int t, int c):f(f), t(t), c(t) {}
// };
// vector<node>e;
//
// void dfs(int x, int cost, int num, int st) {
//   if (cost >= ans) return;
//   if (num + 1 == n) {
//     ans = min(ans, cost + pic[x][st]);
//     //cout << cost + pic[x][st] << endl;
//     return;
//   }
//   for (int i = 1; i <= n; i++) {
//     if (i == x || vis[i] == 1 || i == st) continue;
//     vis[i] = 1;
//     dfs(i, cost + pic[x][i], num+1, st);
//     vis[i] = 0;
//   }
// }
//
// int main(){
//   ans = 20 * 1000 + 5;
//   n = read();
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= n; j++) {
//       pic[i][j] = read();
//       // if (pic[i][j] > 0) {
//       //   e.push_back(node(i, j, pic[i][j]));
//       //   e.push_back(node(j, i, pic[i][j]));
//       // }
//     }
//   }
//   for (int i = 1; i <= n; i++) {
//     dfs(i, 0, 0, i);
//   }
//   cout << ans << endl;
//   return 0;
// }

#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;        //    ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 2e9;//    | |     |  _  |  \ V /
const ll N   = 1e5+5;    //     | |___  | | | |   | |
const ll MOD = 1e9+7;   //       \____| |_| |_|   |_|
ll read() {
  ll x=0,f=1;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
  return x*f;
}

short int n, ans;

short int SIZE=(1<<20);

short int d[20][20];
short int dp[SIZE][20];

int main(){
  for (int _ = 1; _; _--) {
    //ans = 20 * 1000 + 5;
    n = read();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = read();
      }
    }
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

  }
  return 0;
}

/*

4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0
 */
