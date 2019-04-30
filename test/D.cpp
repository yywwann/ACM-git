#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>mp[150000];
int color[150000];
#define ll long long
ll dp[150000][2];
ll mod=1e9+7;
void Dfs(int u,int from)
{
    if(color[u]==1)dp[u][1]=1;
    else dp[u][0]=1;
    for(int i=0;i<mp[u].size();i++)
    {
        int v=mp[u][i];
        if(v == from) continue;
        Dfs(v, u);
        dp[u][1]=((dp[u][1]*(((dp[v][0]+dp[v][1]))%mod))%mod+(dp[u][0]*dp[v][1])%mod)%mod;
        dp[u][0]=(dp[u][0]*((dp[v][0]+dp[v][1]))%mod)%mod;
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)mp[i].clear();
        for(int i=2;i<=n;i++)
        {
            int x;scanf("%d",&x);
            x++;
            mp[x].push_back(i);
            mp[i].push_back(x);
        }
        for(int i=1;i<=n;i++)scanf("%d",&color[i]);
        Dfs(1,-1);
        printf("%lld\n",dp[1][1]%mod);
    }
}
