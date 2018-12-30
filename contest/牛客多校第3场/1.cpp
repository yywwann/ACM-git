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

int n;
struct node{
	int p,a,c,m,val;
	node(){}
	node(int _p,int _a,int _c,int _m,int _val){
		p=_p,a=_a,c=_c,m=_m,val=_val;
	}
	friend bool operator < (node a, node b)
    {
        return a.val < b.val;//结构体中，x小的优先级高
    }
}a[40];
int p,aa,c,m;

ll paths[40][40][40][40];

int dp[40][40][40][40];
int sum;



int main(){
	
	//cout<<36*36*36*36*36<<endl;
	n=read();
	for(int i=0;i<n;i++){
		a[i].p=read();
		a[i].a=read();
		a[i].c=read();
		a[i].m=read();
		a[i].val=read();
		sum+=a[i].val;
	}
	p=read(),aa=read(),c=read(),m=read();
	for(int i=0;i<n;i++){
		for(int P=p;P>=a[i].p;P--){
			for(int A=aa;A>=a[i].a;A--){
				for(int C=c;C>=a[i].c;C--){
					for(int M=m;M>=a[i].m;M--){
						if(dp[P-a[i].p][A-a[i].a][C-a[i].c][M-a[i].m]+a[i].val>dp[P][A][C][M]){
							dp[P][A][C][M]=dp[P-a[i].p][A-a[i].a][C-a[i].c][M-a[i].m]+a[i].val;

							paths[P][A][C][M]=paths[P-a[i].p][A-a[i].a][C-a[i].c][M-a[i].m];
							paths[P][A][C][M]=paths[P][A][C][M]|(1LL<<(i));

						}
					}
				}
			}
		}
	}
	int t=0;
	ll x=paths[p][aa][c][m];
	vector<int>ans;
	for(int i=0;i<n;i++){
		if(x&(1LL<<i)){
			t++;
			ans.push_back(i);
		}
	}
	cout<<t<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<(i==t-1?'\n':' ');
	}
	return 0;
}
