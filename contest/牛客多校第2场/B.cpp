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

int n;
ll p[100000+5];
ll d[100000+5];
ll f[100000+5];
ll sum;
ll ans;
int main(){
	ans=1e18;
	n=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) d[i]=read();
	for(int i=1;i<=n;i++) f[i]=read();
	
	return 0;
}
