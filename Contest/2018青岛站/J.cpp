#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

ll a,b,c,d,v,t;
ll ans;
set<ll>st;
vector<ll>V;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}

int main(){
	for(int _=read();_;_--){
		a=read(),b=read();
		c=read(),d=read();
		v=read(),t=read();
		// st.clear(),
	 	V.clear();
		ans=b+d+(t/a)*b+(t/c)*d;
		//cout<<"ans1: "<<ans<<endl;
		ll LCM=lcm(a,c);
		for(int i=0;;i++){
			bool f1,f2;
			f1=f2=false;
			if(a*i<=min(LCM,t)){
				V.push_back(a*i);
				f1=true;
			}
			if(c*i<=min(LCM,t)){
				V.push_back(c*i);
				f2=true;
			}
			if(f1==false&&f2==false) break;
		}
		sort(V.begin(),V.end());
		V.erase(unique(V.begin(),V.end()),V.end());

		ll cnt;
		if(t%LCM==0) cnt=t/LCM;
		else cnt=t/LCM;
		ll press=0;
		for(int i=1;i<V.size();i++){
			//cout<<V[i]<<' ';
			if(V[i]-V[i-1]>v) press++;
		}//cout<<endl;
		//cout<<"press: "<<press<<endl;
		ans-=press*cnt;
		//cout<<ans<<endl; 
		ll T=t-cnt*LCM;
		//cout<<"T: "<<T<<endl;
		for(int i=1;i<V.size();i++){
			if(V[i]<=T&&V[i]-V[i-1]>v) ans--;
		}
		ans--;
		cout<<ans<<endl;
		//cout<<"V.size: "<<V.size()<<endl;
	}
	return 0;
}
