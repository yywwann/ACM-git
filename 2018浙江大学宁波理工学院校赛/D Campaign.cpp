#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>        		//    ____   _   _  __   __
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

ll n, ans;
struct node{
	ll l, r;
}a[10];
int vis[10];

bool check(){
	ll L=0,R=0;
	for(int i = 1; i <= 7; i++){
		if(vis[i] == 1){
			L += a[i].l;
			R += a[i].r;
		}

	}
	if(L <= n && n <= R) return true;
	return false;
}

void dfs(int x, int sum){
	if(x > 7){
		if(check()){
			ans = max(ans,1LL*sum);
		}
		return;
	}
	dfs(x+1,sum);
	vis[x] = 1;
	dfs(x+1,sum+1);
	vis[x] = 0;
}

int main(){
	for(int _ = read(); _; _--){
		n = read();
		for(int i = 1; i <= 7; i++) a[i].l = read(), a[i].r = read(),vis[i]=0;
		ans = 0;
		dfs(1,0);
		cout << ans << endl;
	}
	return 0;
}
