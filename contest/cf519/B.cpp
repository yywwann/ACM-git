#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e3+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

int n,a[N],x[N];
vector<int>ans;
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();

	for(int i=1;i<=n;i++){
		memset(x,-1,sizeof(x));
		for(int j=1;j<=n;j++){
			int t=a[j]-a[j-1];
			if(x[(j-1)%i]==-1) x[(j-1)%i]=t;
			else if(x[(j-1)%i]!=t) break;
			if(j==n) ans.push_back(i);
		}
	}
	
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
	return 0;
}
