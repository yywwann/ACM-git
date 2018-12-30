#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf  = 0x3f3f3f3f;
const ll maxn = 8000+5;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

ll n,m,t;
ll color[8001];

struct Tree{
  ll l,r;
  ll lazy;
  ll color;
}tree[maxn*4];

void build(int l,int r,int x){
  tree[x].l=l;
  tree[x].r=r;
  tree[x].lazy=0;
  tree[x].color=-1;//表示没有被涂色
  if(l==r) return ;
  int tmp=x*2;
  int mid=(l+r)/2;
  build(l,mid,tmp);
  build(mid+1,r,tmp+1);
}

void update(ll l,ll r,ll c,ll x){

  if(r<tree[x].l||l>tree[x].r) return;
  if(l<=tree[x].l&&r>=tree[x].r){
    tree[x].color=c; //表示整块只有一个c的颜色
    return;
  }
  	if(tree[x].color>=0)//存在颜色，往下更新
	{
	    tree[x<<1].color=tree[x].color;
	    tree[(x<<1)|1].color=tree[x].color;
	    tree[x].color=-2;//表示有多种颜色
	}
  ll tmp=x*2;
  update(l,r,c,tmp);
  update(l,r,c,tmp+1);
  tree[x].color=-2;
}

int pre=-1;

void query(ll l,ll r,ll x){
	//cout<<x<<endl;
    if(tree[x].color==-1){
    	pre=-1;
    	return;
    }
    if(tree[x].color!=-2){
    	if(tree[x].color!=pre){
    		color[tree[x].color]++;
    		pre=tree[x].color;
    	}
    	return;
    }
    
    ll tmp=x*2;
    if(tree[x].l==tree[x].r) return;
    query(l,r,tmp);
    query(l,r,tmp+1);
}

int main(){
	while(scanf("%lld",&n)!=EOF){
		build(1,8000,1);
		int l,r,c;
		while(n--){
			l=read();r=read();c=read();
			update(l+1,r,c,1);
		}
		pre=-1;
		memset(color,0,sizeof(color));
		query(1,8000,1);
		for(int i=0;i<=8000;i++){
			if(color[i]) cout<<i<<' '<<color[i]<<endl;
		}cout<<endl;
	}
	return 0;
}
