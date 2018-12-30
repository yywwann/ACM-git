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

ll n,m;
ll a[105],b[105];

int main(){
	ll _=read();
	while(_--){
		

		n=read();m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();b[i]=read();
			a[i]+=b[i];
		}
		sort(a+1,a+1+n);
		ll ans=1;	
		for(int i=1;i<=n;i++){
			if(ans*a[i]<=m){
				ans*=a[i];
			}
			else{
				cout<<i-1<<endl;
				break;
			}
			if(i==n){
				cout<<n<<endl;
			}
		}
	}	
	return 0;
}
