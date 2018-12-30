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

int n,a,b;
int x[25];

int main(){
	n=read(),a=read(),b=read();
	for(int i=1;i<=n;i++){
		x[i]=read();
	}
	ll ans=0;
	bool flg=true;
	for(int i=1,j=n;i<=j;i++,j--){
		if(x[i]==2){
			if(x[j]==2){
				if(i==j) ans+=min(a,b);
				else ans+=2*min(a,b);
			}
			if(x[j]==1) ans+=b;
			if(x[j]==0) ans+=a;
		}
		if(x[i]==1){
			if(x[j]==2) ans+=b;
			if(x[j]==0) flg=false;
		}
		if(x[i]==0){
			if(x[j]==1) flg=false;
			if(x[j]==2) ans+=a;
		}
	}
	if(flg) cout<< ans <<endl;
	else cout<< -1 <<endl;
	return 0;
}
