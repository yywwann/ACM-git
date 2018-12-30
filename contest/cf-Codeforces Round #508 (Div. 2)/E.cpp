#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF  	= 0x3f3f3f3f;
const ll N		= 1e5+5;
const ll MOD	= 1e9+7;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

/*
 * 使用优先队列优化Dijkstra算法
 * 复杂度O(ElogE)
 */
struct edge{
    int from,to,cost,next;
}E[4*N];
int n,val[N];
int head[N]; 
bool vis[N];
int dis[N];
bool cir[N];
int cnt[N];
int t;
void addedge(int i,int j,int cost){
    E[t].from=i;
    E[t].to=j;
    E[t].cost=cost;
    E[t].next=head[i];
    head[i]=t++;
}
void dfs(int x){
	cir[x]=true;
	for(int i=head[x];i!=-1;i=E[i].next){
		if(cir[E[i].to]==false){
			dfs(E[i].to);
		}
	}
}
void spfa(int n,int s){
    queue <int> q;
    for(int i=1;i<=n;i++) dis[i]=-INF;
    memset(vis,false,sizeof(vis));
    memset(cir,false,sizeof(cir));
    memset(cnt,false,sizeof(cnt));
    q.push(s);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=E[i].next){
            int v=E[i].to;
            if(cir[v]==true) continue;
            if(dis[v]<dis[u]+E[i].cost){
                dis[v]=dis[u]+E[i].cost;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                    if(++cnt[v]>=n) dfs(v);
                }
            }
        }
    }
}


int main(){
	//for(int _=read(); _; _--){
		t=0;
		memset(head,-1,sizeof(head));
		n=read();
		for(int i=1; i<=n; i++){
			int u=read(), v=read(), w=read();
			addedge(u,w,v);
			addedge(w,u,v);
		}
		int S=5, T=6;
		for(int i=1; i<=4; i++){
			addedge(S,i,0);
			addedge(i,T,0);
		}
		spfa(n+2,S);
		cout<< dis[T] <<endl;
	//}
	return 0;
}