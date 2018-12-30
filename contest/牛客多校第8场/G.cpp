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

ll n;

const ll mod = 1000000007;

ll PowerMod(ll a,ll b,ll c){
	ll ans=1;
	a=a%c;
	while(b>0){
		if(b%2==1) ans=(ans*a)%c;
		b=b/2;
		a=(a*a)%c;
	}
	return ans;
}

void Euild(ll a, ll b, ll &x, ll &y)  // x 是 a 关于 b 的乘法逆元
{
    if(0 == b){
        x = 1, y = 0;
        return ;
    }
    Euild(b, a%b, x, y);
    ll flag = x;
    x = y;
    y = flag - a/b * y;
}
//(24 - 42n + 23n^2 - 6n^3 + n^4)/24
int main(){
	n=read(); 
	ll x,y;
	Euild(24, mod, x, y);
	ll ans = 24;
	ans = ans - (42*n)%mod + mod; ans %= mod;
	ans += 1LL*23*PowerMod(n,2,mod); ans %= mod;
	ans = ans - (1LL*6*PowerMod(n,3,mod))%mod + mod; ans %= mod;
	ans += PowerMod(n,4,mod); ans %= mod;
	ans = (ans*x)%mod;
	//cout<<( 1LL*( 1LL*24 - 1LL*42*n + 1LL*23*PowerMod(n, 2, mod) - 1LL*6*PowerMod(n, 3, mod) + PowerMod(n, 4, mod) ) %mod * x)%mod<<endl;
	cout<<ans<<endl;
	return 0;
}
