#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 5e4+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

int n;
struct node{
	int x,y;
}a[50000+5];

vector<int>dis;

inline int id(int x){
	return lower_bound(dis.begin(),dis.end(),x) - dis.begin();
}

struct segt{
	struct seg{
		int l,r;
		int mx;
	};
	
	seg t[100000<<2];
	
	#define lc x<<1
	#define rc x<<1|1
	#define mid ((t[x].l+t[x].r)>>1)
	
	inline void push_up(int x){
		t[x].mx = max(t[lc].mx , t[rc].mx);
	}
	void build(int x,int l,int r){
		t[x].l = l, t[x].r = r, t[x].mx = 0;
		if(l==r) return;
		build(lc,l,mid); build(rc,mid+1,r);
		push_up(x);
	}
	void add(int x,int tar,int val){
		int L = t[x].l, R = t[x].r;
		if(L==R){
			t[x].mx = max(val,t[x].mx);
			return;
		}
		tar<=mid?add(lc,tar,val):add(rc,tar,val);
		push_up(x);
	}
	int query(int x,int l,int r){
		int L = t[x].l, R = t[x].r;
		if(l<=L && R<=r) return t[x].mx;
			int res = 0;
		if(l<=mid) res = max(res,query(lc,l,r));
		if(r>mid)  res = max(res,query(rc,l,r));
		return res;
	}
}tx,ty;

int main(){
	n=read();
	tx.build(1,1,100000);
	ty.build(1,1,100000);
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
		dis.push_back(a[i].x);
		dis.push_back(a[i].y);
	}
	sort(dis.begin(),dis.end());
	dis.erase(unique(dis.begin(),dis.end()),dis.end());
	ll ans=0;
	for(int i=n;i>=1;i--){
		int x=a[i].x,y=a[i].y;
		int idx = id(x)+1, idy = id(y)+1;
		int X=ty.query(1,idy,100000), Y=tx.query(1,idx,100000);
		if(X<x) ans+=x-X;
		if(Y<y) ans+=y-Y;
		ty.add(1,idy,x);tx.add(1,idx,y);
	}
	cout<< ans <<endl;
	return 0;
}
