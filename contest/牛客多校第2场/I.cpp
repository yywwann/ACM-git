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

int n,m;
int s[100000+5];
int x[100000+5];
int z[100000+5];
int y[100000+5];

int main(){
	n=read();m=read();
	if(n%2==0){
		s[n]=1;
		for(int i=2;i<=n/2;i++) s[i]=1;
		x[1]=1;
		for(int i=n-1;i>=n/2+1;i--) x[i]=1;
		z[1]=1;
		for(int i=n-1;i>=n/2+1;i--) z[i]=1;
		y[n]=1;
		for(int i=2;i<=n/2;i++) y[i]=1;
	}
	if(n%2==1){
		s[n]=1;
		for(int i=2;i<=n/2;i++) s[i]=1;
		x[1]=1;
		for(int i=n-1;i>=(n+1)/2+1;i--) x[i]=1;
		z[1]=1;
		for(int i=n-1;i>=(n+1)/2+1;i--) z[i]=1;
		y[n]=1;
		for(int i=2;i<=n/2;i++) y[i]=1;
		s[(n+1)/2]=x[(n+1)/2]=z[(n+1)/2]=y[(n+1)/2]=1;
	}
	while(m--){
		int l=read(),r=read();
		z[l]=y[l]=0;
		s[r]=x[r]=0;
	}
	ll ans=0;
	if(n%2==0){
		for(int i=1;i<=n;i++) ans+=s[i]+x[i]+z[i]+y[i];
	}
	if(n%2==1){
		for(int i=1;i<=n;i++) ans+=s[i]+x[i]+z[i]+y[i];
		ans-=s[(n+1)/2]+x[(n+1)/2]+z[(n+1)/2]+y[(n+1)/2];
		ans+=s[(n+1)/2]|x[(n+1)/2]|z[(n+1)/2]|y[(n+1)/2];
	}
	cout<<ans<<endl;
	return 0;
}
