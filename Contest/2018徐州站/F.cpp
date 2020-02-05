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

int n,a[N];

int main(){
	n=read();
	int _1=0,_2=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]%2==0) _2++;
	} 
	sort(a+1,a+1+n);
	if(a[n]==1){
		cout<<"Bob"<<endl;
	}
	else if(_2%2){
		cout<<"Bob"<<endl;
	}
	else{
		cout<<"Alice"<<endl;
	}
	return 0;
}
