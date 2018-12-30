#include <bits/stdc++.h>
namespace xxx{
using namespace std;
#define ifn(_) if(!(_))
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define CaseT int T;cin >> T;for(int cas=1;cas<=T;cas++)
#define TCase int T;scanf("%d",&T);for(int cas=1;cas<=T;cas++)
#define clr(a,b) memset(a,b,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define _1s __builtin_popcountll
#define sqr(x) ((x)*(x))
#define upd(a,b) ((a)%(b)?(a)/(b)+1:(a)/(b))
#define random(a,b) ((a)+rand()%((b)-(a)+1))
#define fst first
#define sec second
#define MAIN int main
#define GG exit(0)
#define bug cerr << "!!!" << endl;
#define bugc(_) cerr << (#_) << " = " << (_) << endl;
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

}using namespace xxx;
const int N = 1e5+20;
const int M = 10+20;

int n, m;
ll a[M][N];
ll nxt[M][N];

MAIN(){
	FAST_IO;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			if(j>1){
				nxt[i][a[i][j-1]] = a[i][j];
			}
		}
	}
	ll ans = 0;
	ll t = 1;
	for(int i=1;i<=n;i++){
		bool flg = 1;
		for(int j=2;j<=m;j++){
			if(nxt[j][a[1][i]] != nxt[1][a[1][i]]){
				flg = 0;
				break;
			}
		}
		if(flg){
			t++;
		}
		else{
			ans += t*(t+1)/2;
			t = 1;
		}
	}
	if(t>1){
		t--;
		ans += t*(t+1)/2;
	}
	cout << ans << endl;
	GG;
}