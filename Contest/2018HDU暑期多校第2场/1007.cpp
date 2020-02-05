#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf  = 0x3f3f3f3f;
const ll maxn = 1e5+5;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}
#define MAXN 100005
ll n,q,l,r;
ll ans;
char s[10];
ll b[maxn];
struct Tree{
    ll l,r;
    ll b;
    ll add;
    ll ans;
    //ll sum;
}tree[MAXN*4];

void pushup(ll x){
    ll tmp=2*x;
    tree[x].b=min(tree[tmp].b,tree[tmp+1].b);
    tree[x].ans=tree[tmp].ans+tree[tmp+1].ans;
}

void pushdown(ll x){
    ll tmp=2*x;
    tree[tmp].add+=tree[x].add;
    tree[tmp+1].add+=tree[x].add;
    tree[tmp].b+=tree[x].add;
    tree[tmp+1].b+=tree[x].add;
    tree[x].add=0;
}

void build(int l,int r,int x){
    tree[x].l=l;
    tree[x].r=r;
    tree[x].add=0;
    tree[x].ans=0;
    if(l==r){
        tree[x].b=read();
        b[l]=tree[x].b;
        return ;
    }
    int tmp=x*2;
    int mid=(l+r)/2;
    build(l,mid,tmp);
    build(mid+1,r,tmp+1);
    pushup(x);     //如果在建树的过程中给sum赋值，记得后面要pushup
}

void update(ll l,ll r,ll c,ll x){
    if(r<tree[x].l||l>tree[x].r)
        return;
    if(l<=tree[x].l&&r>=tree[x].r){
        if(tree[x].b-1>0){
        	tree[x].b--;
        	tree[x].add--;
        }
        else{
        	if(tree[x].l==tree[x].r){
        		tree[x].ans++;
        		tree[x].b=b[tree[x].l];
        	}
        	else{
        		if(tree[x].add!=0) pushdown(x);
        		int tmp=x*2;
        		if(tree[tmp].b-1==0){
        			update(l,r,c,tmp);
        		}
        		else{
        			tree[tmp].b--;
        			tree[tmp].add--;
        		}
        		if(tree[tmp+1].b-1==0){
        			update(l,r,c,tmp+1);
        		}
        		else{
        			tree[tmp+1].b--;
        			tree[tmp+1].add--;
        		}
        		pushup(x);
        	}
        }
        return;
    }
    if(tree[x].add!=0) pushdown(x);
    ll tmp=x*2;
    update(l,r,c,tmp);    
    update(l,r,c,tmp+1);
    pushup(x);
}

void query(ll l,ll r,ll x){
    if(r<tree[x].l||l>tree[x].r)         //要更新的区间不在该区间上
        return;
    if(l<=tree[x].l&&r>=tree[x].r){      //要更新区间包括了该区间
        ans+=tree[x].ans;
        return ;
    }
    if(tree[x].add!=0)
          pushdown(x);
    ll tmp=x*2;
    query(l,r,tmp);
    query(l,r,tmp+1);
}


int main(){
    while(cin>>n>>q){
        build(1,n,1);
        while(q--){
            scanf("%s%lld%lld",s,&l,&r);
            if(s[0]=='a'){
                update(l,r,1,1);
            }
            else{
                ans=0;
                query(l,r,1);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}