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

int n,m;
ll ans;
int a[11][N];
int pos[11][N];

int main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			pos[i][a[i][j]]=j;
		}
	}
	if(m==1){
		cout<<n*(n+1)/2<<endl;
		return 0;
	}
	ll t=1;
	for(int i=1;i<=n;i++){
		//int l=i,r=i;
		
		int flg=true;
		for(int j=2;j<=m;j++){
			// if(pos[j][a[1][l]]>n||pos[1][a[1][l]]>n){
			// 	flg=false;
			// 	break;
			// }
			//cout<<a[1][pos[1][a[1][l]]]<<" "<<a[j][pos[j][a[1][l]]]<<endl;
			if(a[1][pos[1][a[1][i]]]==a[j][pos[j][a[1][i]]]){
				//cout<<l<<" "<<r<<" "<<"YES"<<endl;
				//pos[j][a[1][l]]++;
			}
			else{
				flg=false;
				break;
			}
		}
		if(flg){
			t++;
		}
		else{
			ans+=(1+t)*t/2;
			t=0;
		}
		// while(flg){
		// 	for(int j=2;j<=m;j++){
		// 		if(pos[j][a[1][l]]>n||pos[1][a[1][l]]>n){
		// 			flg=false;
		// 			break;
		// 		}
		// 		//cout<<a[1][pos[1][a[1][l]]]<<" "<<a[j][pos[j][a[1][l]]]<<endl;
		// 		if(a[1][pos[1][a[1][l]]]==a[j][pos[j][a[1][l]]]){
		// 			//cout<<l<<" "<<r<<" "<<"YES"<<endl;
		// 			pos[j][a[1][l]]++;
		// 		}
		// 		else{
		// 			flg=false;
		// 			break;
		// 		}
		// 		if(j==m) t++,r++,pos[1][a[1][l]]++;
		// 	}
		// }
		// i=r;
		// ans+=(1+t)*t/2;
	}
	if(t>0){
		ans += t*(t+1)/2;
	}
	cout<<ans<<endl;
	return 0;
}
