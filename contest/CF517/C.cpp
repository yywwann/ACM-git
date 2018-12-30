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

ll n,m;
vector<ll>a,b;
int main(){
	n=read(),m=read();
	ll all=n+m,x=0;
	for(int i=1;;i++){
		ll y=(1LL+i)*i/2;
		if(y<=all) x=i;
		else break;
	}
	for(int i=x;i>=1;i--){
		if(n>=i){
			n-=i;
			a.push_back(i);
		}
		else{
			b.push_back(i);
		}
	}
	cout<<a.size()<<endl;
	for(int i=0;i<a.size();i++) cout<<a[i]<<' '; cout<<endl;
	cout<<b.size()<<endl;
	for(int i=0;i<b.size();i++) cout<<b[i]<<' '; cout<<endl;
	return 0;
}
