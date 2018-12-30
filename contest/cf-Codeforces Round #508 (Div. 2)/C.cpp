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
ll a[N],b[N];
struct node{
	ll id,val;
};
vector<node>c;
int cmp(node a,node b){
	return a.val>b.val;
}
ll sum[2];
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),c.push_back(node{0,a[i]});
	for(int i=1;i<=n;i++) b[i]=read(),c.push_back(node{1,b[i]});
	sort(c.begin(),c.end(),cmp);
	int len=c.size();
	for(int i=0;i<len;i++){
		if(i%2==0){
			if(c[i].id==0) sum[0]+=c[i].val;
		}
		else{
			if(c[i].id==1) sum[1]+=c[i].val;
		}
	}
	cout<<sum[0]-sum[1]<<endl;
	return 0;
}
