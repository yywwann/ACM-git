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

ll n, a, b;
ll aa[N], pos[N];
queue<int>q;
int main(){
	n = read(); a = read(), b = read();
	if(a > b) swap(a, b);
	for(int i = 1; i <= n; i++){
		aa[i] = read();
		pos[aa[i]] = i;
	}

	ll l , r, L, R;
	l = r = 0;
	L = 1e6;
	R = 0;
	for(ll i = a; i <= b; i++){
		q.push(i);
		L = min(L, i);
		R = max(R, i);
	}
	for(ll i = min(pos[a],pos[b]); i <= max(pos[a],pos[b]); i++){
		if(aa[i] < L || aa[i] > R){
			//q.push(aa[i]);
			if(aa[i] < L){
				for(int j = aa[i]; j < L; j++){
					q.push(j);
				}
			}
			else{
				for(int j = R+1; j <= aa[i]; j++){
					q.push(j);
				}
			}
			L = min(L, aa[i]);
			R = max(R, aa[i]);
		}
	}


	while(!q.empty()){
		int t = q.front(); q.pop();
		if(l == r && l == 0){
			l = r = pos[t];
		}
		else{
			int p = pos[t];
			if(r < p){
				for(int i = r+1; i <= p; i++){
					if(aa[i] < L || aa[i] > R){
						//q.push(aa[i]);
						if(aa[i] < L){
							for(int j = aa[i]; j < L; j++){
								q.push(j);
							}
						}
						else{
							for(int j = R+1; j <= aa[i]; j++){
								q.push(j);
							}
						}
						L = min(L, aa[i]);
						R = max(R, aa[i]);
					}
				}

				r = p;
			}
			else if(p < l){
				for(int i = p; i <= l-1; i++){
					if(aa[i] < L || aa[i] > R){
						//q.push(aa[i]);
						if(aa[i] < L){
							for(int j = aa[i]; j < L; j++){
								q.push(j);
							}
						}
						else{
							for(int j = R+1; j <= aa[i]; j++){
								q.push(j);
							}
						}
						L = min(L, aa[i]);
						R = max(R, aa[i]);
					}
				}
				l = p;
			}
			else{

			}
		}
	}
	cout << l << ' ' << r << endl;
	return 0;

}

/*
8 4 6
5 4 3 6 1 2 7 8
*/
