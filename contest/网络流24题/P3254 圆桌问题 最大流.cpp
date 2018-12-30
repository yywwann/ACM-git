#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}
#define inf 0x3fffffff
const int maxn=51111;
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
vector<int>as[maxn];
int main()
{
    creat();
    int n,c1,val,c2;
    n=read();  
    s=9,t=10;
    while(t--){
        c1=read(),val=read(),c2=read();
        add_edge(c1,c2+4,val);
    }
    for(int i=1;i<=4;i++){
        add_edge(s,)
    }
    int n,m,sum=0;
    scanf("%d%d",&n,&m);///n 单位数  m餐桌数
    s=0;t=n+m+n*m+1;
    for(int i=1,x;i<=n;i++)
        scanf("%d",&x),add_edge(s,i,x),sum+=x;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        add_edge(i,n+(i-1)*m+j,1),add_edge(n+(i-1)*m+j,j+n+n*m,1);
    for(int i=1,x;i<=m;i++)
        scanf("%d",&x),add_edge(i+n+n*m,t,x);
    if(dinic(t)==sum)
        puts("1");
    else
    {
        puts("0");
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        int f=1;
        for(int j=head[i+n+n*m];~j;j=edge[j].next)
        if(edge[j].to!=t&&edge[j].w==1)
        {
            as[(edge[j].to-n-i)/m+1].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d",as[i][0]);
        for(int j=1;j<as[i].size();j++)
            printf(" %d",as[i][j]);
        printf("\n");
    }
    return 0;
}