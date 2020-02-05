#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define CaseT int T;cin >> T;for(int cas=1;cas<=T;cas++)
#define TCase int T;scanf("%d",&T);for(int cas=1;cas<=T;cas++)
#define clr(a,b) memset(a,b,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define upd(a,b) (a%b?a/b+1:a/b)
#define pb push_back
#define fst first
#define sec second
#define MAIN int main
#define GG exit(0)
#define bug cout << "!!!" << endl;
#define bugc(x) cout << "! " << (x) << endl;
using namespace std;
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
const int M = 2e5+20;
const int N = 2e5+20;

int n,k;
string s,t;

MAIN(){
	CaseT{
		cin >> s >> k;
		t = s;
		n = s.size();
		//min
		int w = k;
		for(int i=0;i<n;i++){
			int pos = -1;
			char mn = s[i];
			for(int j=n-1;j>i;j--){
				if(s[j]<mn){
					if(s[j]=='0'&&i==0) continue;
					mn = s[j];
					pos = j;
				}
			}
			if(pos!=-1){
				swap(s[i],s[pos]);
				w--;
				if(w==0) break;
			}
		}
		//max
		w = k;
		for(int i=0;i<n;i++){
			int pos = -1;
			char mx = t[i];
			for(int j=n-1;j>i;j--){
				if(t[j]>mx){
					mx = t[j];
					pos = j;
				}
			}
			if(pos!=-1){
				swap(t[i],t[pos]);
				w--;
				if(w==0) break;
			}
		}
		cout << s << ' ' << t << endl;
	}
	GG;
}