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
int vis[205][205][3];
int p[205][205];
bool flg;
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

void dfs(int x,int y,int cnt){

	if(cnt>n*n) return;
	if(cnt==n*n&&check()){
		
		flg=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<((p[i][j]==-1)?"":" ")<<p[i][j];
			}cout<<endl;
		}cout<<endl;
		return;
	}
	for(int i=-1;i<=1;i++){
		//cout<<"YES"<<endl;
		if(vis[x][y][i+1]==0){
			vis[x][y][i+1]=1;
			p[x][y]=i;
			dfs(x+y/n,y%n+1,cnt+1);
			p[x][y]=0;
			vis[x][y][i+1]=0;
		}
	}

}

int main(){
	while(cin>>n){
		memset(p,0,sizeof(p));
		memset(vis,0,sizeof(vis));
		cout<<n<<endl;
		flg=0;
		dfs(1,1,0);
	}
	return 0;
}
