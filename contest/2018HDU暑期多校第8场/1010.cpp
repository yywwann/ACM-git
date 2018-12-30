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

int n,m,p,q,ans;
int a[maxn];
int dp[maxn];
vector<int>b,c,d,e;

bool checkisok(int x){
	return binary_search(c.begin(),c.end(),x);
}

struct Tree{
	ll l,r;
	ll max;
}tree[maxn*4];

void pushup(ll x){
	ll tmp=2*x;
	tree[x].max=max(tree[tmp].max,tree[tmp+1].max);
}

void build(int l,int r,int x){
	tree[x].l=l;
	tree[x].r=r;
	if(l==r){
		tree[x].max=a[l];
		return ;
	}
	int tmp=x*2;
	int mid=(l+r)/2;
	build(l,mid,tmp);
	build(mid+1,r,tmp+1);
	pushup(x);	 //如果在建树的过程中给sum赋值，记得后面要pushup
}
int ppos;
void query(ll l,ll r,ll x){
	if(r<tree[x].l||l>tree[x].r)		 //要更新的区间不在该区间上
		return;
	if(l<=tree[x].l&&r>=tree[x].r&&tree[x].max>x){	  //要更新区间包括了该区间
		if(l==r){
			ppos=l;
			return;
		}
		else{

		}
	}
	ll tmp=x*2;
	ll mid=(tree[x].l+tree[x].r)/2;
	
}


int main(){
	for(int _=read(); _; _--){
		n=read(), m=read();
		memset(dp,0,sizeof(dp));
		b.clear(), c.clear(), d.clear();
		//b.push_back(0), c.push_back(0);
		for(int i=1; i<=n; i++) a[i]=read();
		build(1,n,1);
		for(int i=1; i<=n; i++){
			if(i==1) b.push_back(a[i]), c.push_back(i);
			else if(a[i]>b.back()) b.push_back(a[i]), c.push_back(i);
		}
		for(int i=n; i>=1; i--){
			if(i==n) d.push_back(a[i]),dp[i]=d.size();
			else{
				if(a[i]>a[i+1]) d.push_back(a[i]),dp[i]=d.size();
				else{
					while(!d.empty()&&a[i]>=d.back()){
						d.pop_back();
					}
					d.push_back(a[i]),dp[i]=d.size();
				}
			}
		}
		//for(int i=0; i<b.size(); i++) cout<<b[i]<<endl;
		//for(int i=0; i<d.size(); i++) cout<<d[i]<<endl;
		while(m--){
			p=read(), q=read();
			if(checkisok(p)){
				if(q>=a[p]){
					int sub=lower_bound(b.begin(), b.end(), q)-b.begin()-pre-1;
					cout<<b.size()-sub<<endl;
				}
				else{

					
				}
			}
			else{
				if(q<=a[p]) cout<<b.size()<<endl;
				else{
					int pre=lower_bound(c.begin(),c.end(),p)-c.begin()-1;
					//cout<<pre<<endl;
					if(q>b[pre]){
						int sub=lower_bound(b.begin(), b.end(), q)-b.begin()-pre-1;
						cout<<b.size()-sub+1<<endl;
					}
					else{
						cout<<b.size()<<endl;
					}
					
				}
			}
		}

	}
	return 0;
}
