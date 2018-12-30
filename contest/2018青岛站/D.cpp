#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const LL N=1e5+5;

LL a,b,c,d,v,t,T,ans,cnt,ps,LCM;
bool flag1,flag2;
vector<LL>st;

LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}

LL lcm(LL a,LL b){
	return a/gcd(a,b)*b;
}

void input(){
	cin>>a>>b>>c>>d>>v>>t;
}

void solve(){
	cnt=t/LCM,ps=0;
	for(int i=1;i<st.size();i++){
		if(st[i]-st[i-1]>v) ps++;
	}
	ans-=ps*cnt;
	T=t-cnt*LCM;
	for(int i=1;i<st.size();i++){
		if(st[i]<=T&&st[i]-st[i-1]>v) 
			ans--;
	}
}

void init(){
	st.clear();
}

void output(){
	cout<<ans-1<<endl;;
}

int main(){
	int C;
	cin>>C;
	while(C--){
		input();init();
		ans=b+d+(t/a)*b+(t/c)*d;
		LCM=lcm(a,c);
		for(int i=0;;i++){
			flag1=flag2=false;
			if(a*i<=min(LCM,t)){
				st.push_back(a*i);
				flag1=true;
			}
			if(c*i<=min(LCM,t)){
				st.push_back(c*i);
				flag2=true;
				
			}
			if(!flag1&&!flag2) 
				break;
		}
		sort(st.begin(),st.end());
		st.erase(unique(st.begin(),st.end()),st.end());
		solve();
		output();
	}
	return 0;
}