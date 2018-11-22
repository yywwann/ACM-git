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

int a[N], b[N];
int n, m, x, y;
int type[N];
int flg;

bool check1(){
	for(int i = 1; i <= m; i++) if(type[a[i]] == type[b[i]] && type[a[i]] != -1) return false;
	return true;
}

bool check3(){
	for(int i = 1; i <= n; i++){
		if(type[i] == -1) return false;
	}
	return true;
}

void dfs(int pos){
	if(flg) return;
	if(pos == m + 1){
		if(check3()){
			flg = true;
		}
		return;
	}

	if(type[a[pos]] == -1 && type[b[pos]] == -1){
		type[a[pos]] = 1, type[b[pos]] = 0;
		dfs(pos + 1);
		type[a[pos]] = 0, type[b[pos]] = 1;
		dfs(pos + 1);
		type[a[pos]] = -1, type[b[pos]] = -1;
	}
	else if(type[a[pos]] == 1){
		if(type[b[pos]] == -1){
			type[b[pos]] = 0;
			dfs(pos + 1);
			type[b[pos]] = -1;
		}
		if(type[b[pos]] == 0){
			dfs(pos + 1);
		}
	}
	else if(type[a[pos]] == 0){
		if(type[b[pos]] == -1){
			type[b[pos]] = 1;
			dfs(pos + 1);
			type[b[pos]] = -1;
		}
		if(type[b[pos]] == 1){
			dfs(pos + 1);
		}
	}
}

bool check2(){
	flg = false;
	dfs(1);
	return flg == true;
}

int main(){
	while(cin >> n){
		flg = false;
		memset(type, -1, sizeof(type));
		m = read(), x = read(), y = read();
		for(int i = 1; i <= m; i++) a[i] = read(), b[i] = read();
		for(int i = 1; i <= x; i++) type[read()] = 1;
		for(int i = 1; i <= y; i++) type[read()] = 0;

		if(check1() && check2()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
