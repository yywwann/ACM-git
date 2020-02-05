#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e6+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

ll n;
char z,str[N];

int main(){
	for(int _=read();_;_--){
		n=read();
		cin>>z;
		scanf("%s",str);
		string ans="";
		for(int i=0;i<n;i++){
			int t=abs(z-str[i]);
			if(t>=10) ans+="11";
			else if(t>0) ans+="01";
			else ans+="00";
		}
		ll len=ans.size();
		for(int i=0;i<ans.size();i++){
			if(ans[i]=='0') len--;
			else break;
		}
		if(len==0) len=1;
		cout<< len <<endl;
	}	
	return 0;
}
