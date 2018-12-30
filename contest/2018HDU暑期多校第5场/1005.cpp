#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int _,m,R,x,y,r;

const double pi=acos(-1.);
double norm(double x) {
	return min(max(x,-1.0),1.0);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&m,&R);
		double ans=2*pi*R;
		rep(i,0,m) {
			scanf("%d%d%d",&x,&y,&r);
			int d1=x*x+y*y;
			if (d1<(R-r)*(R-r)) continue;
			if (d1>(R+r)*(R+r)) continue;
//			printf("%.10f\n",ans);
			double t1=acos(norm((R*R+d1-r*r)/2./R/sqrt(d1)));
			ans-=2*t1*R;
			double t2=acos(norm((r*r+d1-R*R)/2./r/sqrt(d1)));
			ans+=2*t2*r;
		}
		printf("%.10f\n",ans);
	}
}
