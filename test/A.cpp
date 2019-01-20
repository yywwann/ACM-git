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
const ll MOD = 1e18+7;
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

ll n, cnt;

int main(){
	for(int _ = read(); _; _--){
		n = read();
		cnt = 0;
		n--;
		while(n){
			if(n%2 == 1) cnt++;
			n /= 2;
		}
		cout << PowerMod(2, cnt, MOD) << endl;
	}
	return 0;
}
