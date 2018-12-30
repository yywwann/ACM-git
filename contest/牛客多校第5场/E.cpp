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
struct node{
	int s[5];
	int si[5];
	int id;
}a[maxn];
int mp[maxn];
int main(){
	n=read();
	for(int i=1;i<=4*n;i++){
		ll _=read();
		mp[_]=i/4;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=4;j++){
			a[i].s[j]=read();
			a[i].si[j]=mp[a[i].s[j]];
		}
		sort(a[i].si+1,a[i].si+1+4);
		if(a[i].si[1]==a[i].si[2]){
			a[i].id=a[i].si[1];
		}
		else if(a[i].si[2]==a[i].si[3]){
			a[i].id=a[i].si[2];
		}
		else if(a[i].si[3]==a[i].si[4]){
			a[i].id=a[i].si[3];
		}
		else{
			a[i].id=a[i].si[1];
		}
		for(int j=1;j<=4;j++){
			if(a[i].id!=a[i].si[j]) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
