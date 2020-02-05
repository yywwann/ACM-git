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

int t;
int n;
ll a[200];
int size;
int vis[15];
ll dp[15][200];

void dfs(int cnt,ll pos){
	if(cnt==n+1){
		a[size]=pos;
		size++;
	}
	else{
		dfs(cnt+1,pos<<1);
		if(vis[cnt-1]==0){
			vis[cnt]=1;
			dfs(cnt+1,pos<<1|1);
			vis[cnt]=0;
		}
	}
}

void init(){
	size=0;
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	dfs(1,0);
}

int main(){
	t=read();
	while(t--){
		n=read();
		init();
		//for(int i=0;i<size;i++) cout<<i<<' '; cout<<endl;
		for(int i=1;i<=n;i++){
			if(i==1) for(int j=0;j<size;j++) dp[i][j]=1;
			else{
				for(int j=0;j<size;j++){
					ll sum=0;
					for(int k=0;k<size;k++){
						if((a[j]&a[k])==0) sum+=dp[i-1][k];
					}
					dp[i][j]=sum;
					//cout<<sum<<endl;
				}
			}
		}
		ll ans=0;
		for(int i=0;i<size;i++) ans+=dp[n][i];
		cout<<ans<<endl;
	}
	return 0;
}
