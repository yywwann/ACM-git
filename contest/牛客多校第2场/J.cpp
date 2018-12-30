#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#define MAXN 1000000+5
#define ll long long
using namespace std;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

ll n,m,t;
ll ans;

struct Tree{
	ll l,r;
	ll sum;
	ll max;
	ll num;
}tree[MAXN*4];

void pushup(ll x){
	ll tmp=2*x;
	tree[x].max=max(tree[tmp].max,tree[tmp+1].max);
	tree[x].num=tree[tmp].num+tree[tmp+1].num;
}

//建树
void build(int l,int r,int x){
	tree[x].l=l;
	tree[x].r=r;
	if(l==r){
		scanf("%lld",&tree[x].sum);
		tree[x].max=tree[x].sum;
		tree[x].num=1;
		return ;
	}
	int tmp=x*2;
	int mid=(l+r)/2;
	build(l,mid,tmp);
	build(mid+1,r,tmp+1);
	pushup(x);	 //如果在建树的过程中给sum赋值，记得后面要pushup
}
//区间更新
void update(ll l,ll r,ll c,ll x){
	if(r<tree[x].l||l>tree[x].r||tree[x].max==0)
		return;
	if(tree[x].r==tree[x].l){
		if(tree[x].sum!=c) tree[x].num=tree[x].max=tree[x].sum=0;
		return;
	}
	ll tmp=x*2;
	update(l,r,c,tmp);	//  !!!
	update(l,r,c,tmp+1);
	pushup(x);
}
//查询
// ll query(ll l,ll r,ll x){
// 	if(r<tree[x].l||l>tree[x].r)		 //要更新的区间不在该区间上
// 		return;
// 	if(l<=tree[x].l&&r>=tree[x].r){	  //要更新区间包括了该区间
// 		return tree[x].sum;
// 	}
// 	if(tree[x].add)
// 		pushdown(x);
// 	ll tmp=x*2;
// 	ll mid=(tree[x].l+tree[x].r)/2;
// 	if(r<=mid)
// 		return query(l,r,tmp);
// 	else if(l>mid)
// 		return query(l,r,tmp+1);
// 	else{
// 		return query(l,mid,tmp)+query(mid+1,r,tmp+1);
// 	}
// }

int main(){
	n=read();m=read();t=read();
	build(1,n*m,1);
	//cout<<n*m-tree[1].num<<endl;
	while(t--){
		int x1=read(),y1=read(),x2=read(),y2=read(),tt=read();
		int M=y2-y1;
		for(int i=x1;i<=x2;i++){
			//cout<<(i-1)*m+y1<<' '<<(i-1)*m+y1+M<<endl;
			update((i-1)*m+y1,(i-1)*m+y2,tt,1);
			//cout<<n*m-tree[1].num<<endl;
		}
	}
	cout<<n*m-tree[1].num<<endl;
}
