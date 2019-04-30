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

ll n, m, h;
ll p[N], v[N], d[N], f[N];

int main(){
	for(int _ = read(); _; _--){
		n = read(), m = read(), h = read();
		for(int i=1;i<=n;i++){
			p[i] = read(), v[i] = read(), d[i] = read();
			f[i] = h;
		}
		p[n+1] = m;
		f[n+1] = h;
		f[0] = h;
		for(int i=1;i<=n+1;i++){
			for(int j=0;j<i;j++){
				if(f[j] + v[j] <= 0 || f[j] + v[j] + d[j] * (p[i] - p[j]) <= 0) continue;
				f[i] = max(f[i], f[j] + v[j] + d[j] * (p[i] - p[j]));
			}
		}
		cout << f[n+1] << endl;
	}
	return 0;
}
