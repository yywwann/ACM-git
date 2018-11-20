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

ll a[3];
vector<ll>v;

int main(){
	while(cin >> a[0] >> a[1] >> a[2]){
		v.clear();

		sort(a, a + 3);
		ll mina = a[0];
		ll minsub = a[2];
		for(int i = 0; i < 3; i++){
			for(int j = i + 1; j < 3; j++){
				minsub = min(minsub, abs(a[i] - a[j]));
			}
		}
		ll ans = 1;
		v.push_back(a[0]);
		v.push_back(a[1]);
		v.push_back(a[2]);
		while(minsub){
			ans++;
			ll t = minsub;
			for(int i = 0; i < v.size(); i++){
				t = min(t, abs(minsub - v[i]));
			}
			v.push_back(minsub);
			minsub = t;
		}
		cout << ans << endl;
	}
	return 0;
}
