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
ll n,C,a[2*N],b[2*N],c[2*N],sum[2*N],SUM,ans;
struct Tree{
	ll l,r;
	ll sum,add;
}tree[N*4];

void pushup(ll x){
	ll tmp=2*x;
	tree[x].sum=min(tree[tmp].sum,tree[tmp+1].sum);
}

void build(int l,int r,int x){
	tree[x].l=l;
	tree[x].r=r;
	tree[x].add=0;
	if(l==r){
		tree[x].sum=sum[l];
		return ;
	}
	int tmp=x*2;
	int mid=(l+r)/2;
	build(l,mid,tmp);
	build(mid+1,r,tmp+1);
	pushup(x);	 //如果在建树的过程中给sum赋值，记得后面要pushup
}

void query(ll l,ll r,ll x){
	if(r<tree[x].l||l>tree[x].r)		 //要更新的区间不在该区间上
		return;
	if(l<=tree[x].l&&r>=tree[x].r){	  //要更新区间包括了该区间
		ans=min(ans,tree[x].sum);
		return ;
	}
	ll tmp=x*2;
	ll mid=(tree[x].l+tree[x].r)/2;
	if(r<=mid)
		query(l,r,tmp);
	else if(l>mid)
		query(l,r,tmp+1);
	else{
		query(l,mid,tmp);
		query(mid+1,r,tmp+1);
	}
}



int main(){
	for(int _=read();_;_--){
		n=read(),C=read();
		SUM=0;
		for(int i=1;i<=n;i++) a[i]=read(),a[i+n]=a[i],SUM+=a[i]; 
		for(int i=1;i<=n;i++) b[i]=read(),b[i+n]=b[i],SUM-=b[i];
		if(SUM+C<0) cout<<-1<<endl;
		else{
			for(int i=1;i<=2*n;i++) sum[i]=0,c[i]=a[i]-b[i],sum[i]+=sum[i-1]+c[i];
			build(1,2*n,1);
			bool flag=0;
			for(ll i=1;i<=n;i++){
				ans=1e18;
				query(i,i+n-1,1);
				ans-=sum[i-1];
				if(ans+C>=0){
					cout<<i<<endl;
					break;
				}
			}
		}
	}	
	return 0;
}


