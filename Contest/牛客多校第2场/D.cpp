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

int t;
int n;
ll a[100000+5];

int main(){
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		int i=1;
		ll profit=0;
		ll trans=0;
		int t=a[1];
		while(i<n){
			ll MAX=t;
			while(i+1<=n&&a[i+1]>=MAX){
				i++;
				MAX=a[i];
			}
			if(MAX>t){
				trans+=2;
				profit+=MAX-t;
			}
			while(i+1<=n&&a[i+1]<=MAX){
				i++;
				MAX=a[i];
			}
			t=MAX;
		}
		cout<<profit<<' '<<trans<<endl;
	}
	return 0;
}
