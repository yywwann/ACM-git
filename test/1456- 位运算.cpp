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

int n;
int a[40];

int main(){
	while(cin >> n, n) {
		int idx = 0;
		int _1 = 0;
		memset(a, 0, sizeof(a));
		while(n) {
			if(n % 2) _1++;
			a[idx++] = n % 2;
			n /= 2;
		}
		int __1 = 0;
		for(int i = 0; i < idx; i++) {
			if(a[i] == 1) __1++;
			if(a[i] == 1 && a[i + 1] == 0) {
				a[i + 1] = 1;
				__1--;
				if(i + 1 == idx) idx++;
				for(int j = 0; j < __1; j++) a[j] = 1;
				for(int j = __1; j <= i; j++) a[j] = 0;
				break;
			}
		}
		ll ans = 0;
		ll t= 1;
		for(int i = 0; i < idx; i++) {
			ans += t * a[i];
			t *= 2;
		}
		cout << ans << endl;
	}
	return 0;
}
