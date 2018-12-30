#include<bits/stdc++.h>
using namespace std;
 
#define next VIVONEX
const int N=100005,M=500005;
 
int n,m,G[N],tot,e[M],next[M],deg[N],top,stk[M],vis[M],fa[N],w;
vector<int> ji[N],Ans[N];
 
int getfa(int u)
{
    return u==fa[u]?u:fa[u]=getfa(fa[u]);
}
 
inline void adde(int u,int v)
{
//    cout<<u<<" "<<v<<endl;
    next[++tot]=G[u];G[u]=tot;e[tot]=v;
}
 
void dfs(int u)
{
    for(int &v=G[u];v!=0;v=next[v])
    {
        if(vis[v>>1]) continue;

        int t=v;
        vis[v>>1]=1;
        dfs(e[v]);
        stk[++top]=(t&1?-(t>>1):t>>1);
    }
}
 
#define clr(_) memset(_,0,sizeof(_))
 
void solve()
{
    clr(G);clr(deg);clr(vis);
    tot=1;
    for(int i=1;i<=n;i++)
        ji[i].clear(),Ans[i].clear(),fa[i]=i;
    for(int i=1,u,v;i<=m;i++)
        scanf("%d%d",&u,&v),adde(u,v),adde(v,u),deg[u]++,deg[v]++,fa[getfa(u)]=getfa(v);
    for(int i=1;i<=n;i++)
        if(deg[i]&1) ji[getfa(i)].push_back(i);  //把奇数点分到一个联通块里
    w=0;
    for(int i=1;i<=n;i++)
        if(fa[i]==i)
        {
            if(!ji[i].size())
            {
                top=0;
                dfs(i);
                ++w;
                while(top)
                    Ans[w].push_back(stk[top--]);
            }
            else
            {
                for(int j=0;j<ji[i].size();j+=2)
                    adde(ji[i][j],ji[i][j+1]),adde(ji[i][j+1],ji[i][j]);
            //    cout<<tot<<endl;
                top=0;
                dfs(i);
                vector<int> pos;
                for(int i=top;i>=1;i--)
                    if(stk[i]>m||stk[i]<-m) pos.push_back(i);       //把新加的边扔进去
                pos.push_back(0);
                for(int i=0;i<pos.size()-1;i++)
                {
                    w++;
                    for(int j=pos[i]-1;j>pos[i+1];j--)
                        Ans[w].push_back(stk[j]); 			//把两个新加的边之间的欧拉路扔进去
                }
                //w++;
                // for(int j=pos[pos.size()-1]-1;j>=1;j--)
                //     Ans[w].push_back(stk[j]);

                for(int j=top;j>pos[0];j--)
                    Ans[w].push_back(stk[j]);
            }
        }
    int t=w;
    for(int i=1;i<=w;i++)
        if(Ans[i].size()==0)
            t--;
    cout<<t<<endl;
    for(int i=1;i<=w;i++)
        if(Ans[i].size()!=0)
        {
            printf("%d",Ans[i].size());
            for(int j=0;j<Ans[i].size();j++)
                printf(" %d",Ans[i][j]);
            puts("");
        }
}
 
int main()
{
    while(cin>>n>>m)
        solve();
    return 0;
}