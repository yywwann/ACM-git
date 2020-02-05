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
int n;
int p[205][205];

map<int,int>mp;

bool check(){
	int cnt=0;
	mp.clear();
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=1;j<=n;j++){
			t+=p[i][j];
		}
		if(mp[t]==0){
			mp[t]=1;
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=1;j<=n;j++){
			t+=p[j][i];
		}
		if(mp[t]==0){
			mp[t]=1;
			cnt++;
		}
	}
	return cnt==n*2;
}

// impossible
// possible
int main(){
	t=read();
	while(t--){
		memset(p,0,sizeof(p));
		n=read();
		if(n%2){
			cout<<"impossible"<<endl;
		}
		else{
			for(int i=1;i<=n/2;i++){
				for(int j=1;j<=n/2;j++){
					p[i][j]=-1;
				}
			}
			for(int i=n/2+1;i<=n;i++){
				for(int j=n/2+1;j<=n;j++){
					p[i][j]=1;
				}
			}
			for(int i=1;i<=n/2;i++){
				for(int j=(n/2+1);j<=n+1-i;j++){
					p[i][j]=-1;
				}
			}
			p[n/2+1][1]=-1;
			p[n/2+1][n/2]=p[n][1]=1;
			for(int i=n/2+2;i<=n;i++){
				for(int j=n+2-i;j<=n;j++){
					p[i][j]=1;
				}
			}
			p[n][n/2]=0;
			cout<<"possible"<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cout<<p[i][j]<<' ';
				}cout<<endl;
			}
			// if(check()) cout<<"YES"<<endl;
			// else cout<<"NO"<<endl;
		}
	}
	return 0;
}
