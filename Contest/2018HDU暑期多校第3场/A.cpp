#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf  = 0x3f3f3f3f;
const ll maxn = 1e6+5;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}


ll n,m,k,p,q,r,mod;
ll a[10*maxn];
ll que[10*maxn];
int main(){
	int _=read();
	while(_--){
		n=read();m=read();k=read();p=read();q=read();r=read();mod=read();
		for(int i=1;i<=k;i++){
			a[i]=read();
		}
		for(int i=k+1;i<=n;i++){
			ll aa=a[i-1];
			aa=(p*aa+q*i+r)%mod;
			a[i]=aa;
		}
		ll ans1=0,ans2=0;
		int h=1,t=0;

		for(int i=n;i>=1;i--){
			while(h<=t&&a[que[t]]<=a[i]) t--;
			que[++t]=i;
			if(i+m-1<=n){
				while(que[h]>=i+m) h++;
				ans1+=i^a[que[h]];
				ans2+=i^(t-h+1);
			}
		}
		cout<<ans1<<' '<<ans2<<endl;
		
		
	}
	return 0;
}
