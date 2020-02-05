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

ll n,k;
vector<int>ans;
int main(){
	n=read(),k=read();
	int a=k+1,b=2*k+1;
	for(int i=a;i<=b;i++){
		int pos=i-k;
		int st=pos;
		while(pos<=n){
			if(pos+k>=n){
				for(;st<=pos;st+=b) ans.push_back(st);
				cout<<ans.size()<<endl;
				for(int i=0;i<ans.size();i++) cout<<ans[i]<<' ';
				return 0;
			}
			pos+=b;
		}
	}
	return 0;
}