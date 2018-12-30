#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf  = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

int n,m,q;
vector<int>v[4*maxn];
int vis[4*maxn];

void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(!vis[v[x][i]]){
			dfs(v[x][i]);
		}
	}
}

int main(){
	n=read();m=read();q=read();
	while(q--){
		int l=read();
		int r=read();
		v[l].push_back(r+n);
		v[r+n].push_back(l);
	}
	int cnt=-1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			cnt++;
		}
	}
	for(int i=1+n;i<=n+m;i++){
		if(!vis[i]){
			dfs(i);
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
