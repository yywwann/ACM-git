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

ll n;
ll num[10];
ll a[N];
ll b[N];
int main(){
	n = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		num[a[i]] ++;
	}
	b[0] = 0;
	for(int i = 1; i <= n; i++){
		if(b[i-1] == 0){
			if(num[4]) num[4]--, b[i] = 4;
			else if(num[2]) num[2]--, b[i] = 2;
			else num[0]--, b[i] = 0;
		}
		else if(b[i-1] == 4){
			if(num[0]) num[0]--, b[i] = 0;
			else if(num[2]) num[2]--, b[i] = 2;
			else num[4]--, b[i] = 4;
		}
		else{
			if(num[0]) num[0]--, b[i] = 0;
			else if(num[4]) num[4]--, b[i] = 4;
			else num[2]--, b[i] = 2;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ans += (b[i] - b[i-1]) * (b[i] - b[i-1]);
	}
	cout << ans << endl;
	return 0;
}
