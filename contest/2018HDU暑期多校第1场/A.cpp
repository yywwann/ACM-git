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

ll t,n;


int main(){
	t=read();
	while(t--){
		n=read();
		if(n%3==0){
			cout<<1LL*(n/3)*(n/3)*(n/3)<<endl;
		}
		else if(n%4==0){
			cout<<1LL*(n/2)*(n/4)*(n/4)<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}
