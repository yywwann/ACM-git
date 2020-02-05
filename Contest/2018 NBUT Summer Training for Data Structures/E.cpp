#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAXN 100005
#define ll long long
using namespace std;
ll n,m,t;
ll ans,MAX,MIN;

struct Tree{
  ll l,r;
  ll lazy;
  ll color;
}tree[MAXN*4];

void pushup(ll x){
  ll tmp=2*x;
  tree[x].color=tree[tmp].color|tree[tmp+1].color;
}

void pushdown(ll x){
  ll tmp=2*x;
  tree[tmp].color=tree[tmp+1].color=tree[x].color;
  tree[tmp].lazy=tree[tmp+1].lazy=1;
  tree[x].lazy=0;
}

void build(int l,int r,int x){
  tree[x].l=l;
  tree[x].r=r;
  tree[x].lazy=0;
  if(l==r){
    tree[x].color=1;
    return ;
  }
  int tmp=x*2;
  int mid=(l+r)/2;
  build(l,mid,tmp);
  build(mid+1,r,tmp+1);
  pushup(x);   //如果在建树的过程中给sum赋值，记得后面要pushup
}

void update(ll l,ll r,ll c,ll x){
  if(r<tree[x].l||l>tree[x].r)
    return;
  if(l<=tree[x].l&&r>=tree[x].r){
    tree[x].color=1<<(c-1);
    tree[x].lazy=1;
    return;
  }
  if(tree[x].lazy) pushdown(x);
  ll tmp=x*2;
  update(l,r,c,tmp);
  update(l,r,c,tmp+1);
  pushup(x);
}

ll color;

void query(ll l,ll r,ll x){
    if(r<tree[x].l||l>tree[x].r)     //要更新的区间不在该区间上
        return;
    if(l<=tree[x].l&&r>=tree[x].r){   //要更新区间包括了该区间
        color|=tree[x].color;
        return ;
    }
    if(tree[x].lazy) pushdown(x);
    ll tmp=x*2;
    ll mid=(tree[x].l+tree[x].r)/2;
    query(l,r,tmp);
    query(l,r,tmp+1);
}

ll f(ll x){
    int t=0;
    for(int i=30;i>=1;i--){
        if(x&(1<<(i-1))) t++;
    }
    return t;
}

int main(){
  scanf("%lld%lld%lld",&n,&t,&m);
  build(1,n,1);
  while(m--){
    char o;
    int l,r,c;
    cin>>o;
    if(o=='P'){
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        color=0;
        query(l,r,1);
        printf("%lld\n",f(color));
    }
    else{
        scanf("%d%d%d",&l,&r,&c);
        if(l>r) swap(l,r);
        update(l,r,c,1);
    }
  }
}