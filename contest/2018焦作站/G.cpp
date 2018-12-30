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

ll PowerMod(ll a,ll b,ll c){
	int ans=1;
	a=a%c;
	while(b>0){
		if(b%2==1) ans=(ans*a)%c;
		b=b/2;
		a=(a*a)%c;
	}
	return ans;
}

ll euler(ll n)
{
	int res=n,i;
	for(i=2;i*i<=n;i++) {
		if(n%i==0) {
			res=res/i*(i-1);
			while(n%i==0) n=n/i;
		}
	}
	if(n!=1) res=res/n*(n-1);
	return res;
}
//  phi[mod]=1000000006
string str;
ll n;
int main(){
	//cout<<euler(MOD)<<endl;
	for(int _=read();_;_--){
		cin>>str;
		n=0;
		for(int i=0;i<str.size();i++){
			n=n*10+(str[i]-'0');
			n%=1000000006;
		}
		cout<< PowerMod(2,(n-1+MOD)%MOD,MOD)<<endl;
	}
	return 0;
}
