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

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll n,k;
ll a[maxn];
ll b[maxn];
ll cnt[maxn];
set<ll>st;
vector<ll>ans;
int main(){
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[i]=a[i]%k;
		cnt[b[i]]++;
		if(b[i]>0){
			st.insert(gcd(b[i],k));
		}
	}
	for(auto &x:st){
		for(int i=0;i<k;i++) if(cnt[i]) cnt[(i+x)%k]++;
		for(int i=0;i<k;i++) if(cnt[i]) cnt[(i+x)%k]++;
	}
	for(int i=0;i<k;i++) if(cnt[i]) ans.push_back(i);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
	return 0;
}
