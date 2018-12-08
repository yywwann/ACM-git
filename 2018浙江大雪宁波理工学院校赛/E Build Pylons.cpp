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
const ll N   = 1e3+5;           //   \____| |_| |_|   |_|
const ll MOD = 1e9+7;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

ll n, k;
ll p[N];

int main(){
	for(int _ = read(); _; _--){
		n = read(), k = read();
		for(int i=1;i<=n;i++) p[i] = read();
		sort(p+1, p+n+1);
		ll ans = k;
		for(int i=2;i<=n;i++){
			ll x = p[i] - p[i-1];
			ans += x*x;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
