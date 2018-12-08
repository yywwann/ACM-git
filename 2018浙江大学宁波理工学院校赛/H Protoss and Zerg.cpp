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
const ll MOD = 998244353;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

ll PowerMod(ll a,ll b,ll c){
        ll ans = 1;
        a = a % c;
        while(b > 0){
                if(b % 2 == 1) ans = (ans * a) % c;
                b = b / 2;
                a = (a * a) % c;
        }
        return ans;
}

ll n;
ll a, b;
ll ans;

int main(){
	for(int _ = read(); _; _--){
		n = read();
		ans = 1;
		while(n--){
			a = read(), b = read();
			ll t = 0;
			t = (t + PowerMod(2,a,MOD))%MOD;
			t = (t - 1) % MOD;
			t = (t + PowerMod(2,b,MOD))%MOD;
			t = (t - 1) % MOD;
			ans = (ans * t) % MOD;
		}
		cout << ans << endl;

	}
	return 0;
}
