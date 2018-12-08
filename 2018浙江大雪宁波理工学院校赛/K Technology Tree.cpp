#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>        		//    ____   _   _  __   __
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

ll n, q, fa[20005];
ll a[N], b[N], dpa[N], dpb[N];

ll init(ll w[], ll dpw[], int x){
	if(dpw[x] != 0){
		return dpw[x];
	}
	ll ans = w[x];
	ll t = x;
	if(fa[t]!=0){
		ans += init(w,dpw,fa[t]);
		t = fa[t];
	}
	return dpw[x] = ans;
}

int main(){
	for(int _ = read(); _; _--){
		n = read(), q = read();
		for(int i = 1; i <= n; i++){
			a[i] = read();
			b[i] = read();
			dpa[i] = 0;
			dpb[i] = 0;
			fa[i] = 0;
		}
		for(int i = 2; i <= n; i++) fa[i] = read();
		for(int i = 1; i <= n; i++){
			init(a,dpa,i);
			init(b,dpb,i);
		}
		//cout << " on" << endl;
		while(q--){
			ll x = read();
			cout << dpa[x] << " " << dpb[x] << endl;
		}
	}
	return 0;
}
