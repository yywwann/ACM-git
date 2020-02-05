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

int t;
int n,m;
map<ll,ll>num;
ll v[maxn];
vector<ll> a;
vector<ll> b;
ll sum[maxn];
ll cnt[maxn];
ll MAXN;

bool check(int x){
	map<ll,ll>mp;
	mp.clear();
	ll xx=0;
	for(int i=0;i<b.size();i++){
		mp[b[i]]++;
	}
	for(auto i:mp){
		if(i.second>mp[x]){
			xx+=i.second;
		}
		if(i.second==mp[x]) xx++;
	}
	return xx-1<=m;
}

int main(){
	//freopen("/Users/cccccccccchy/compare/data.in","r",stdin);
	t=read();
	while(t--){
		num.clear();
		a.clear();
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			v[i]=0;
			ll aa=read();
			a.push_back(aa);
			num[aa]++;
		}
		for(auto i:num){
			v[i.second]++;
		}
		int pre=0,now=0;
		for(int i=n;i>=1;i--){
			now+=pre;
			sum[i]=now;
			if(v[i]>0){
				pre+=v[i];
				sum[i]+=pre-1;

			}
		}
		ll ans=-1;
		for(int i=0;i<a.size();i++){
			if(sum[num[a[i]]]<=m)
				ans=max(ans,a[i]);
		}
		cout<<ans<<endl;
    	
	}
	return 0;
}
