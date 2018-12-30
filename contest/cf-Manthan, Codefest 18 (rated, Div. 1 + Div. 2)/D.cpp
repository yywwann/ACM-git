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

int n, a[2*N];
struct node{
	int x,st;
};
int vis[2*N];
vector<int>G[2*N];
vector<int>ans;
int cnt[2*N];
int mp[2*N];
int id[2*N];

int cmp(int a, int b){
	return id[a]<id[b];
}

void bfs(int x){
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		x=q.front(); q.pop();
		vis[x]=1;
		ans.push_back(x);
		sort(G[x].begin(), G[x].end(), cmp);
		for(int i=0;i<G[x].size();i++){
			if(vis[G[x][i]]==1) continue;
			q.push(G[x][i]);
		}
		//cout<<st<<endl;
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int u=read(), v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		a[i]=read();
		id[a[i]]=i;
	} 
	if(a[1]!=1){
		cout<<"No"<<endl;
		return 0;
	}

	bfs(1);
	//for(int i=1;i<=n;i++) cout<<cnt[i]<<" "; cout<<endl;
	//for(int i=1;i<=n;i++) cout<<mp[a[i]]<<" "; cout<<endl;
	for(int i=1;i<=n;i++){
		if(a[i]!=ans[i-1]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
