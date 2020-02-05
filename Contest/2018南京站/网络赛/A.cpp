#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e5+5;
const int M=2e5+5;
const int INF=0x3f3f3f3f;
LL read() {
    LL X = 0, p = 1; char c = getchar();
    for(; c > '9' || c < '0'; c = getchar()) if(c == '-') p = -1;
    for(; c >= '0' && c <= '9'; c = getchar()) X = X * 10 + c - '0';
    return X * p;
}
int n,m,k,st,en,cnt;
int head[N];
LL dis[20][N];//dis[i][j]±íê??¨μ?á?iì??a·?±?ê±μ?jμ?μ?×??ì?· 
bool vis[20][N];

struct EE{
    int first,second;
};

struct node{
    int next,to,w;
}edge[M];

void init(){
    cnt=2;
    memset(head,0,sizeof(head));
}

void add(int u,int v,int w){
    edge[cnt].next=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt++;
}

void spfa(LL st){
    for(int i=0;i<=k;i++)
        for(int j=0;j<=n;j++)
            dis[i][j]=1e18;
    memset(vis,0,sizeof(vis));
    queue<EE>q;
    EE U;
    U.first=0;
    U.second=st;
    q.push(U);
    dis[0][st]=0;
    while(!q.empty()){
        int u=q.front().second;
        int x=q.front().first;
        q.pop();
        vis[x][u]=false;
        for(int i=head[u];i;i=edge[i].next){
            node t=edge[i];
            if(dis[x][u]+t.w<dis[x][t.to]){
                dis[x][t.to]=dis[x][u]+t.w;
                if(!vis[x][t.to]){
                    vis[x][t.to]=true;
                    U.first=x;
                    U.second=t.to;
                    q.push(U);
                }
            }
            if(x+1<=k&&dis[x][u]<dis[x+1][t.to]){
                dis[x+1][t.to]=dis[x][u];
                if(!vis[x+1][t.to]){
                    vis[x+1][t.to]=true;
                    U.first=x+1;
                    U.second=t.to;
                    q.push(U);
                }
            }
        }
    }
}

int main(){
    int T;LL a,b,c;
    T=read();
    while(T--){
        n=read(), m=read(), k=read();
        init();
        st=1,en=n;
        rep(i,1,m){
            a=read(), b=read(), c=read();
            add(a,b,c);
        }
        spfa(st);
        LL ans=1e18;
        rep(i,0,k)
            ans=min(ans,dis[i][en]);
        printf("%lld\n",ans);
    }
    return 0;
}