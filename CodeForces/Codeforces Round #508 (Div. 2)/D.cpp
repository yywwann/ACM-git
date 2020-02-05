#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 5e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

int n;
ll a[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n==1){
		cout<<a[n]<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	ll ans=a[1];
	if(a[1]>=0){
		for(int i=1;i<n;i++){
			if(a[i]-a[i+1]<0){
				ans=a[i]-a[i+1];
				a[i]=0;
				a[i+1]=0;
				break;
			}
		}
	}
	for(int i=(ans==a[1]?2:1);i<n;i++){
		if(a[i]<0) ans+=a[i];
		else ans-=a[i];
	}
	cout<<a[n]-ans<<endl;
	return 0;
}
