#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 3e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

ll n,m;
ll a[N],b[N];
ll suma,sumb;
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),suma+=a[i];
	m=read();
	for(int i=1;i<=m;i++) b[i]=read(),sumb+=b[i];
	if(suma!=sumb){
		cout<<-1<<endl;
		 return 0;
	} 
	ll ta,tb,ans;
	ans=ta=tb=0;
	 int i=0,j=0;
	// while(i<=n&&j<=m){
	// 	if(ta<=tb) i++, ta+=a[i];
	// 	else j++, tb+=b[j];
	// 	if(ta==tb) ans++, cout<<i<<endl;
	// }
	//cout<<ans-1<<endl;
	for(i=1,j=1;i<=n;i++){
		ta+=a[i];
		for(;ta>tb&&j<=m;j++){
			tb+=b[j];
		}
		if(ta==tb){
			ans++;
			//cout<<i<<endl;
		}
	}	
	//cout<<ta<<' '<<tb<<endl;
	//cout<<i<<" "<<j<<endl;
	cout<<ans<<endl;
	
	return 0;
}
