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

ll c,n;

int main(){
	c=read();n=read();
	ll x=(n/c)*c;
	ll y=(n/c-1)*c;
	//cout<<x<<' '<<y<<endl;
	if(x*y==0){
		if(x==0) cout<<-1<<endl;
		else cout<<x*x<<endl;
	}
	else cout<<x*y<<endl;
	return 0;
}
