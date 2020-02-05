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

ll n;
ll a[2*maxn];

int main(){
	n=read();
	for(int i=1;i<=2*n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+2*n);
	ll ans=(a[n]-a[1])*(a[n*2]-a[n+1]);
	for(int i=2;i<=n;i++){
		ans=min(ans,(a[n-1+i]-a[i])*(a[n*2]-a[1]));
	}
	
	cout<<ans<<endl;
	return 0;
}
