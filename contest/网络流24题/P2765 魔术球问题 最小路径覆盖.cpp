#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x3fffffff
using namespace std;
const int maxn=11111;
int head[maxn],sign,cur[maxn];
int s,t,d[maxn];
struct node
{
    int to,w,next;
} edge[maxn*20];
void creat()
{
    memset(head,-1,sizeof(head));
    sign=0;
}
void add_edge(int u,int v,int w)
{
    edge[sign].to=v;
    edge[sign].w=w;
    edge[sign].next=head[u];
    head[u]=sign++;
 
    edge[sign].to=u;
    edge[sign].w=0;
    edge[sign].next=head[v];
    head[v]=sign++;
}
int bfs()
{
    queue<int>q;
    memset(d,0,sizeof(d));
    d[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=head[top]; ~i; i=edge[i].next)
        {
            int to=edge[i].to;
            if(edge[i].w>0&&d[to]==0)
            {
                d[to]=d[top]+1;
                if(to==t)
                    return 1;
                q.push(to);
            }
        }
    }
    return d[t]!=0;
}
int dfs(int top,int flow)
{
    if(top==t)
        return flow;
    int ans=0,x=0;
    for(int i=cur[top]; ~i; i=edge[i].next)
    {
        int to=edge[i].to;
        if(edge[i].w>0&&d[to]==d[top]+1)
        {
            x=dfs(to,min(flow-ans,edge[i].w));
            edge[i].w-=x;
            edge[i^1].w+=x;
            if(edge[i].w)
                cur[top] = i;
            ans+=x;
            if(ans==flow)
                return flow;
        }
    }
    if(ans==0)
        d[top]=0;
    return ans;
}
int dinic(int n)
{
    int ans=0;
    while(bfs())
    {
        for(int i=0; i<=n; i++)
            cur[i]=head[i];
        ans+=dfs(s,inf);
    }
    return ans;
}
int id[11111],wid[11111];
int vis[maxn];
int go(int x,int &f)
{
    int loc=wid[x];
    vis[x]=1;
    for(int i=head[loc]; ~i; i=edge[i].next)
        if(edge[i].w==1&&edge[i].to!=t)
            go(edge[i].to/2,f);
    if(f==1)f=0;
    else putchar(' ');
    printf("%d",x);
}
 
int main()
{
    creat();
    int n;
    scanf("%d",&n);
    s=0,t=11110;
    int cnt=2;
    int ans=0,i=0;
    for(i=1; i-ans<=n+1; i++)
    {
        id[i]=cnt++;
        wid[i]=cnt++;
        add_edge(s,id[i],1);
        add_edge(wid[i],t,1);
        for(int j=1; j<i; j++)
        {
            int se=sqrt(i+j);
            if(se*se==i+j)
            {
                add_edge(id[j],wid[i],1);
            }
        }
        ans+=dinic(t);
    }
    int as=i-2;
    printf("%d\n",i-2);
    for(i=head[t]; ~i; i=edge[i].next)
        if(edge[i].w==1&&!vis[edge[i].to/2])
        {
            int f=1;
            go(edge[i].to/2,f);
            puts("");
        }
    for(i=1;i<=as;i++)
    if(!vis[i])printf("%d\n",i);
    return 0;
}