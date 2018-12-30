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
vector<ll>a, ans;

int main(){
	for(int _ = 1; _; _--){
		n = read();
		for(int i = 1; i*i <= n; i++){
			if(n % i == 0){
				a.push_back(i);
				if(i != n/i) a.push_back(n/i);
				//cout << i << ' ';
			}
		}//cout << endl;
		sort(a.begin(), a.end());
		for(int i = 0; i < a.size(); i++){
			ll t = a[i];
			ll num = n / t;
			ll Tans = (1 + t * (num-1) + 1) * num / 2;
			ans.push_back(Tans);
		}
		for(int i = ans.size()-1; i >= 0; i--){
			cout << ans[i] << ' ';
		}
	}
	return 0;
}
