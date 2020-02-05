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

ll n, s, a[2*N];

int main(){
	n=read(), s=read();
	for(int i=1; i<=n; i++){
		a[i]=read();
	}
	sort(a+1, a+1+n);
	ll ans=0;
	int mid=(n+1)/2;
	if(a[mid]<s){
		for(int i=mid; i<=n; i++){
			if(a[i]<s) ans+=s-a[i];
			else if(a[i]>=s) break;
		}
	}
	else if(a[mid]>s){
		for(int i=mid; i>=1; i--){
			if(a[i]>s) ans+=a[i]-s;
			else if(a[i]<=s) break;
		}
	}
	cout<< ans <<endl;
	return 0;
}
