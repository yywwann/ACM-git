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

int n,k;
string s;
ll num[26];
int main(){
	n=read(),k=read();
	cin>>s;
	ll ans=INF;
	for(int i=0;i<n;i++){
		num[s[i]-'A']++;
	}
	for(int i=0;i<k;i++){
		ans=min(ans,num[i]);
	}
	cout<< ans*k <<endl;
	return 0;
}
