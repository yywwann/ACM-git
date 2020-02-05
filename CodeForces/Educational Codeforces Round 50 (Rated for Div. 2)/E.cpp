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

ll n,m,k;

int main(){
	for(int _=read();_;_--){
		n=read(),m=read(),k=read();
		if(n>m) swap(n,m);
		if(k<m){
			cout<<-1<<endl;
			continue;
		}
		if(n%2!=m%2) cout<<k-1<<endl;
		else if(n%2!=k%2) cout<<k-2<<endl;
		else cout<<k<<endl;
		// ll ans=n;
		// ll sub=m-n;
		// k-=n;
		// if(sub==0){
		// 	if(k%2==1) ans+=k-2;
		// 	else ans+=k;
		// }
		// else if(sub%2==0){
		// 	ans+=k-2;
		// }
		// else{
		// 	ans+=k-1;
		// }
		
		
		// cout<<ans<<endl;
	}	
	return 0;
}
