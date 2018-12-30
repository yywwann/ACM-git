#include<bits/stdc++.h>         //    ____   _   _  __   __   
using namespace std;            //   / ___| | | | | \ \ / /   
#define ll long long            //  | |     | |_| |  \ V /    
const ll INF = 0x3f3f3f3f;      //  | |___  |  _  |   | |     
const ll N   = 1e5+5;           //   \____| |_| |_|   |_|     
const ll MOD = 1e9+7;               
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f; 
}

ll n,m,k,a[1005];
string f;
ll dpmax[1005][10],dpmin[1005][10];
int main(){
	for(int _=read();_;_--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			dpmax[i][0]=dpmin[i][0]=k;
			for(int j=1;j<=m;j++) dpmin[i][j]=1e18,dpmax[i][j]=-1e18;
		} 
		dpmax[0][0]=dpmin[0][0]=k;
		for(int j=1;j<=m;j++) dpmin[0][j]=1e18,dpmax[0][j]=-1e18;
		cin>>f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i>=j){
					if(f[j-1]=='+'){
						dpmax[i][j]=max({dpmax[i-1][j-1]+a[i],dpmin[i-1][j-1]+a[i],dpmax[i-1][j]});
						dpmin[i][j]=min({dpmax[i-1][j-1]+a[i],dpmin[i-1][j-1]+a[i],dpmin[i-1][j]});
					}
					if(f[j-1]=='-'){
						dpmax[i][j]=max({dpmax[i-1][j-1]-a[i],dpmin[i-1][j-1]-a[i],dpmax[i-1][j]});
						dpmin[i][j]=min({dpmax[i-1][j-1]-a[i],dpmin[i-1][j-1]-a[i],dpmin[i-1][j]});
					}
					if(f[j-1]=='*'){
						dpmax[i][j]=max({dpmax[i-1][j-1]*a[i],dpmin[i-1][j-1]*a[i],dpmax[i-1][j]});
						dpmin[i][j]=min({dpmax[i-1][j-1]*a[i],dpmin[i-1][j-1]*a[i],dpmin[i-1][j]});
					}
					if(f[j-1]=='/'){
						if(a[i]==0) continue;
						dpmax[i][j]=max({dpmax[i-1][j-1]/a[i],dpmin[i-1][j-1]/a[i],dpmax[i-1][j]});
						dpmin[i][j]=min({dpmax[i-1][j-1]/a[i],dpmin[i-1][j-1]/a[i],dpmin[i-1][j]});
					}
					// cout<<"---"<<i<<" "<<j<<"---"<<endl;
					// cout<<dpmax[i][j]<<' '<<dpmin[i][j]<<endl;
					// cout<<"------"<<endl;
				}
				
			}
		}
		ll ans=-1e18;
		for(int i=m;i<=n;i++){
			ans=max(ans,1LL*dpmax[i][m]);
		}
		cout<<ans<<endl;
	}	
	return 0;
}
