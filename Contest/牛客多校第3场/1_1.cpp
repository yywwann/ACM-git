#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define CaseT int T;cin >> T;for(int cas=1;cas<=T;cas++)
#define clr(a,b) memset(a,b,sizeof(a))
#define sgn(a) ((a)==0?0:(a)/abs(a))
#define upd(a,b) (a%b?a/b+1:a/b)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fst first
#define sec second
#define MAIN int main
#define GG exit(0)
#define bug cout << "!!!" << endl;
#define bugc(x) cout << (x) << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
//const int M = 1e5+20;
const int N = 40+20;

struct node{
	int p,a,c,m,g;
};

int n,P,A,C,M;
node t[N];
int dp[N][N][N][N],path[N][N][N][N];
vector<int>ans;

MAIN(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d%d",&t[i].p,&t[i].a,&t[i].c,&t[i].m,&t[i].g);
	}
	scanf("%d%d%d%d",&P,&A,&C,&M);
	for(int idx=0;idx<n;idx++){
		if(t[idx].g==0) continue;
		for(int i=P;i>=0;i--){
			if(i<t[idx].p) continue;
			for(int j=A;j>=0;j--){
				if(j<t[idx].a) continue;
				for(int k=C;k>=0;k--){
					if(k<t[idx].c) continue;
					for(int l=M;l>=0;l--){
						if(l<t[idx].m) continue;
						if(dp[i-t[idx].p][j-t[idx].a][k-t[idx].c][l-t[idx].m]+t[idx].g>dp[i][j][k][l]){
							dp[i][j][k][l] = dp[i-t[idx].p][j-t[idx].a][k-t[idx].c][l-t[idx].m]+t[idx].g;
							path[i][j][k][l] = idx;
						}
					}
				}
			}
		}
	}
	int val = dp[P][A][C][M];
	int idx;
	while(val>0){
		val -= dp[P][A][C][M];
		idx = path[P][A][C][M];
		ans.pb(idx);
		P -= t[idx].p;
		A -= t[idx].a;
		C -= t[idx].c;
		M -= t[idx].m;
	}
	int sz = ans.size();
	cout << sz << endl;
	for(int i=0;i<sz;i++){
		if(i!=0) cout << ' ';
		cout << ans[i];
	}
	cout << endl;
	GG;
}