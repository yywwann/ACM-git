#include <bits/stdc++.h>
namespace xxx{
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define CaseT int T;cin >> T;for(int cas=1;cas<=T;cas++)
#define TCase int T;scanf("%d",&T);for(int cas=1;cas<=T;cas++)
#define clr(a,b) memset(a,b,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define upd(a,b) (a%b?a/b+1:a/b)
#define random(a,b) ((a)+rand()%((b)-(a)+1))
#define fst first
#define sec second
#define MAIN int main
#define GG exit(0)
#define bug cout << "!!!" << endl;
#define bugc(x) cout << "! " << (x) << endl;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
 
inline ll rd(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
ll pow_mod(ll a,ll n){
    if(n==0) return 1;
    ll x = pow_mod(a,n/2);
    ll ans = x*x%MOD;
    if(n&1) ans = ans*a%MOD;
    return ans;
}
 
}using namespace xxx;
const int N = 2e6+20;

struct segt{
	struct seg{
		ll l,r;
		ll mn;
	};
	
	ll* a;
	seg t[N<<2];
	
	#define lc x<<1
	#define rc x<<1|1
	#define mid ((t[x].l+t[x].r)>>1)
	
	inline void modify(ll *arr){
		a = arr;
	}
	inline void push_up(ll x){
		t[x].mn = min(t[lc].mn,t[rc].mn);
	}
	void build(ll x,ll l,ll r){
		t[x].l = l, t[x].r = r;
		if(l==r){
			t[x].mn = a[l];
			return;
		}
		build(lc,l,mid); build(rc,mid+1,r);
		push_up(x);
	}
	ll query(ll x,ll l,ll r){
		ll L = t[x].l, R = t[x].r;
		if(l<=L && R<=r) return t[x].mn;
		ll res = 1e18;
		if(l<=mid) res = min(query(lc,l,r),res);
		if(r>mid)  res = min(query(rc,l,r),res);
		return res;
	}
};

ll n, c, b;
ll a[N];
segt t;

bool ok(ll x){
//	cout << t.query(1,x,x+n-1) - a[x-1] << ' ' << (-c) << endl;
	if(t.query(1,x,x+n-1) - a[x-1] >= -c) return 1;
	return 0;
}

MAIN(){
	TCase{
		n = rd(), c = rd();
		for(ll i=1;i<=n;i++) a[i] = rd();
		for(ll i=1;i<=n;i++){
			b = rd();
			a[i] -= b;
			a[i+n] = a[i];
		}
		for(ll i=1;i<=2*n;i++){
			a[i] += a[i-1];
		}
//		for(ll i=1;i<=2*n;i++){
//			cout << a[i] << ' ';
//		}
//		cout << endl;
		t.modify(a);
		t.build(1,1,2*n);
		bool flg = 0;
		for(ll i=1;i<=n;i++){
			if(ok(i)){
				printf("%lld\n",i);
				flg = 1;
				break;
			}
		}
		if(!flg) puts("-1");
	}
	GG;
}

2
3 0
3 4 5
5 4 3
3 100
-3 -4 -5
30 40 50