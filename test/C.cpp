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
const ll MOD = 998244353;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int m;
ll _2[105];

int main(){
	_2[1] = 3;
	_2[0] = 1;
	for(int i = 1; i <= 100; i++){
		_2[i] = _2[i-1] * 3 % MOD;
		//cout << i << ' ' << _2[i];
	}
	m = read();
	cout << _2[m] << endl;
	// // m = read();
	// // ll ans = 0;
	// // for(int i = 0; i <=m ;i++){
	// // 	ans = (ans + _2[i]) % MOD;
	// // }
	// // cout << ans << endl;
	// for(int n = 0; n <= 10; n++){
	// 	m = _2[n];
	// 	ll ans = 0;
	// 	for(int i = 0; i < m; i++){
	// 		for(int j = 0; j < m; j++){
	// 			if(i + j == (i | j)) ans++;
	// 		}
	// 	}
	// 	cout << ans << ',';
	// }
}
