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
const ll MOD = 1e18+7;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

ll n,x;
ll a[105], b[105];

int main(){
	n = read(), x = read();
	for(int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
	for(int i = n; i >= 1; i--){
		if(a[i] == 1) x -= b[i];
		if(a[i] == 2) x += b[i];
		if(a[i] == 3) x /= b[i];
		if(a[i] == 4) x *= b[i];
	}
	cout << x << endl;
	return 0;
}
