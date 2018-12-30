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
const ll N   = 1e6+5;           //   \____| |_| |_|   |_|
const ll MOD = 998244353;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}


ll I[2*N];

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



ll T(ll n, ll k){
	ll ans = (n-k+1+(k==0?1:0));
	ans = ans * I[(n+1)] % MOD;
	//ans /= I[n-k+2];
	ans = ans * PowerMod(I[(n-k+2)] , MOD-2, MOD);
	return ans % MOD;
}

ll n;
int main(){
	I[0] = 1;
	for(int i = 1; i <= 2000000; i++){
		I[i] = I[i-1] * i % MOD;
	}
	//cout << T(0,0) << endl;
	cin >> n;
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	n--;

	ll ans = 0;
	for(int i = 0; i < n; i++){
		//cout << T(n-1,i) << endl;
		ans = (ans + (i+1) * T(n-1,i) % MOD) % MOD;
		//cout << (i+1) * T(n-1,i) << endl;
	}

	ans = (ans * (n+1)) % MOD;
	cout << ans << endl;
	return 0;
}


//https://oeis.org/search?q=1%2C4%2C15%2C40%2C60&language=english&go=Search
