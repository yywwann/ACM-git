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
const int mod = 1000000007;
ll t,k;
ll dp[100000+5][2];
ll sum[100000+5];
int main(){
	t=read();k=read();
	for(int i=0;i<=k-1;i++){
		dp[i][0]=1;
		dp[i][1]=0;
	}
	for(int i=k;i<=100000;i++){
		dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;
		dp[i][1]=dp[i-k][0]%mod;
	}
	for(int i=1;i<=100000;i++){
		sum[i]=(sum[i-1]+dp[i][1]+dp[i][0])%mod;
	}
	while(t--){
		int l=read(),r=read();
		cout<<(sum[r]-sum[l-1]+mod)%mod<<endl;
	}
	return 0;
}
