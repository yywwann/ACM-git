#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 2e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}
#define ll long long
using namespace std;
ll n,m;
ll ans;
ll t,a[N],sum[N];

struct Tree{
    ll l,r;
    ll max,min;
}tree[N*4];

void pushup(ll x){
    ll tmp=2*x;
    tree[x].max=max(tree[tmp].max,tree[tmp+1].max);
    tree[x].min=min(tree[tmp].min,tree[tmp+1].min);
}

void build(int l,int r,int x){
    tree[x].l=l;
    tree[x].r=r;
    //tree[x].add=0;
    if(l==r){
        tree[x].min=tree[x].max=sum[l];
        return ;
    }
    int tmp=x*2;
    int mid=(l+r)/2;
    build(l,mid,tmp);
    build(mid+1,r,tmp+1);
    pushup(x);   //如果在建树的过程中给sum赋值，记得后面要pushup
}

void query(ll l,ll r,ll x,ll t){
    if(r<tree[x].l||l>tree[x].r||tree[x].min>=t)         //要更新的区间不在该区间上
        return;
    if(l<=tree[x].l&&r>=tree[x].r&&tree[x].max<t){   //要更新区间包括了该区间
        ans+=tree[x].r-tree[x].l+1;
        return;
    }
    ll tmp=x*2;
    ll mid=(tree[x].l+tree[x].r)/2;
    if(r<=mid)
        query(l,r,tmp,t);
    else if(l>mid)
        query(l,r,tmp+1,t);
    else{
        query(l,mid,tmp,t);
        query(mid+1,r,tmp+1,t);
    }
}

int main(){
    n=read(); t=read();
    for(ll i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
    build(1,n,1);
    for(int i=1;i<=n;i++){
        query(i,n,1,sum[i-1]+t);
    }
    cout<<ans<<endl;
}