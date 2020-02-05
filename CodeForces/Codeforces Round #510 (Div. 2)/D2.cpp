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
const int N = 5e5+20;

struct BIT{
	int size,t[N];
	void init(int n){
		size = n;
		clr(t,0);
	}
	void add(int x,int v){
		for(int i=x;i<=size;i+=(i&-i)) t[i] += v;
	}
	int sum(int x,int ans = 0){
		for(int i=x;i;i-=(i&-i)) ans += t[i];
		return ans;
	}
	int Kth(int k){
		int ans = 0, cnt = 0;
		for(int i=20;i>=0;i--){
			ans += (1<<i);
			if(ans>size||cnt+t[ans]>=k) ans -= (1<<i);
			else cnt += t[ans];
		}
		return ans+1;
	}
};

ll n, t, ans;
ll a[N], s[N];
vector<ll>sep; 
BIT bit;

inline ll id(ll x){
	return lower_bound(all(sep),x) - sep.begin() + 1;
}

MAIN(){
	bit.init(500000);
	n = rd(), t = rd();
	for(int i=2;i<=n+1;i++){
		a[i] = rd();
		s[i] = s[i-1] + a[i];
		sep.push_back(s[i]);
		sep.push_back(s[i]-t);
	}
	sep.push_back(0);
	sort(all(sep));
	sep.erase(unique(all(sep)),sep.end());
	bit.add(id(0),1);
	for(int i=2;i<=n+1;i++){
		ans += bit.sum(500000) - bit.sum(id(s[i] - t));
		bit.add(id(s[i]),1);
	}
	printf("%lld\n",ans);
	GG;
}