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
int a[55],b[55];
int suma,sumb;
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),suma+=a[i];
	for(int i=1;i<=n;i++) b[i]=read(),sumb+=b[i];

	if(suma<sumb) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;

	return 0;
}
