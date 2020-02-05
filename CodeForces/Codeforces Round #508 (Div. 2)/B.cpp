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

int n;
vector<int>a,b;
int suma,sumb;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	a.clear(),b.clear();
	suma=sumb=0;
	n=read();
	if(n<=2){
		cout<<"No"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i%2) a.push_back(i),suma+=i;
		else b.push_back(i),sumb+=i;
	}
	cout<<"Yes"<<endl;
	cout<<a.size();
	for(int i=0;i<a.size();i++) cout<<' '<<a[i]; cout<<endl;
	cout<<b.size();
	for(int i=0;i<b.size();i++) cout<<' '<<b[i]; cout<<endl;


}
