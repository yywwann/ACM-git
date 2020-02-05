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

int t;
int n,m;
struct node{
	int l,r;
}a[maxn];

int cmp(node a,node b){
	if(a.l==b.l) return a.r>b.r;
	return a.l<b.l;
}
priority_queue<int, vector<int>, greater<int> >q;
int ans[maxn];

int main(){
	t=read();
	while(t--){
		memset(ans,0,sizeof(ans));
		while(!q.empty()) q.pop();
		

		n=read();m=read();
		for(int i=1;i<=n;i++) q.push(i);
		for(int i=1;i<=m;i++) a[i].l=read(),a[i].r=read(); 

		sort(a+1,a+1+m,cmp);
		int MAXR=0,MAXL=0;

		for(int i=1;i<=m;i++){
			if(i==1){
				for(int j=a[i].l;j<=a[i].r;j++){
					ans[j]=q.top();
					q.pop();
				}
			}
			else{
				if(a[i].r<=MAXR) continue;
				else{
					if(a[i].l>MAXR){
						for(int j=MAXL;j<=MAXR;j++) q.push(ans[j]);
						for(int j=a[i].l;j<=a[i].r;j++){
							ans[j]=q.top();
							q.pop();
						}
					}
					else if(MAXL<=a[i].l&&a[i].l<=MAXR&&MAXR<=a[i].r){
						for(int j=MAXL;j<a[i].l;j++){
		                    q.push(ans[j]);
		                }
		                for(int j=MAXR+1;j<=a[i].r;j++){
		                    ans[j]=q.top();
		                    q.pop();
		                }
					}
					
				}
			}
			MAXL=max(MAXL,a[i].l);
			MAXR=max(MAXR,a[i].r);
		}
		for(int i=1;i<=n;i++){
			if(ans[i]==0) cout<<1<<(i==n?'\n':' ');
			else cout<<ans[i]<<(i==n?'\n':' ');
		}
	}
	return 0;
}
