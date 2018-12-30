#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 5e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

struct BIT{
	ll size,t[N];
	void Init(ll n){
		size = n;
		memset(t,0,sizeof(t));
	}
	void Add(ll x,ll v){
		for(ll i=x;i<=size;i+=(i&-i)) t[i] += v;
	}
	ll Sum(ll x){
		ll ans=0;
		for(ll i=x;i;i-=(i&-i)) ans += t[i];
		return ans;
	}
	ll Kth(ll k){
		ll ans = 0, cnt = 0;
		for(ll i=20;i>=0;i--){
			ans += (1LL<<i);
			if(ans>size||cnt+t[ans]>=k) ans -= (1LL<<i);
			else cnt += t[ans];
		}
		return ans+1;
	}
};

ll n, t, ans;
ll a[N], sum[N];
vector<ll>v; 
BIT bit;

ll Id(ll x){
	return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}

void input(){
	n = read(), t = read();
	
	for(ll i=2;i<=n+1;i++){
		a[i] = read(); 
	}
}

void solve(){
	for(ll i=2;i<=n+1;i++){
		sum[i] = sum[i-1] + a[i];
		v.push_back(sum[i]-t);
		v.push_back(sum[i]); 
	}
	v.push_back(0);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());

	bit.Init(N-5);
	bit.Add(Id(0),1);
	for(ll i=2;i<=n+1;i++){
		ans += bit.Sum(500000) - bit.Sum(Id(sum[i] - t));
		bit.Add(Id(sum[i]),1);
	}
	cout<< ans <<endl;
}

int main(){
	input();
	solve();

}