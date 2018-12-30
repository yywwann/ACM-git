//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define CaseT int T;cin >> T;for(int cas=1;cas<=T;cas++)
#define clr(a,b) memset(a,b,sizeof(a))
#define sgn(a) ((a)==0?0:(a)/abs(a))
#define upd(a,b) (a%b?a/b+1:a/b)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fst first
#define sec second
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
const int M = 2e5+20;
const int N = 1e5+20;

ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n,op,l,r,v;
multiset<int>st[N];
int a[N],id[N],tag[N];
multiset<int>::iterator it;

int query(int l,int r,int c){
	int ans = -1;
	int id1 = id[l], id2 = id[r];
	if(id1==id2){
		for(int i=l;i<=r;i++) if(a[i]+tag[id1]<c) ans = max(ans,a[i]+tag[id1]);
	}
	else{
		for(int i=l;id[i]==id1;i++) if(a[i]+tag[id1]<c) ans = max(ans,a[i]+tag[id1]);
		for(int i=r;id[i]==id2;i--) if(a[i]+tag[id2]<c) ans = max(ans,a[i]+tag[id2]);
		for(int i=id1+1;i<id2;i++){
			it = st[i].lower_bound(c - tag[i]);
			if(it==st[i].begin()) continue;
			it--;
			ans = max(ans,*it+tag[i]);
		}
	}
	return ans;
}

void update(int l,int r,int v){
	int id1 = id[l], id2 = id[r];
	if(id1==id2){
		for(int i=l;i<=r;i++){
			st[id1].erase(st[id1].find(a[i]));
			st[id1].insert(a[i]+=v);
		}
	}
	else{
		for(int i=l;id[i]==id1;i++){
			st[id1].erase(st[id1].find(a[i]));
			st[id1].insert(a[i]+=v);
		}
		for(int i=r;id[i]==id2;i--){
			st[id2].erase(st[id2].find(a[i]));
			st[id2].insert(a[i]+=v);
		}
		for(int i=id1+1;i<id2;i++){
			tag[i] += v;
		}
	}
}

int main(){
	n=read();
	int unit = sqrt(n);
	for(int i=0;i<n;i++){
		a[i]=read();
		id[i] = i/unit;
		st[id[i]].insert(a[i]);
	}
	for(int i=1;i<=n;i++){
		//scanf("%d%d%d%d",&op,&l,&r,&v);
		op=read();l=read();r=read();v=read();
		l--,r--;
		if(op==0) update(l,r,v);
		else printf("%d\n",query(l,r,v));
	}
	return 0;
}