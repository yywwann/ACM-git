#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x3fffffff
using namespace std;
const int maxn=555;
int head[maxn],sign,cur[maxn];
int s,t,d[maxn];
struct node
{
    int to,w,next;
} edge[maxn*50];
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

int n,m;
int vis[maxn];
int go(int x,int &f)
{
    int loc=x+n;
    vis[x]=1;
    for(int i=head[loc]; ~i; i=edge[i].next)
        if(edge[i].w==1&&edge[i].to!=n*2+1)
            go(edge[i].to,f);
    if(f==1)f=0;
    else putchar(' ');
    printf("%d",x);
}
int main()
{
    scanf("%d%d",&n,&m);
    creat();
    s=0,t=n*2+1;
    for(int i=1; i<=n; i++)
        add_edge(s,i,1),add_edge(i+n,t,1);
    int x,y;
    while(m--)
        scanf("%d%d",&x,&y),add_edge(x,y+n,1);
    int ans=n-dinic(t);
    for(int i=head[t]; ~i; i=edge[i].next)
        if(edge[i].w==1&&!vis[edge[i].to-n])
        {
            int f=1;
            go(edge[i].to-n,f);
            puts("");
        }
    printf("%d\n",ans);
    return 0;
}