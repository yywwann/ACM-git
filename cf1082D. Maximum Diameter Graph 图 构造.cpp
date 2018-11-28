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
struct node{
	int id, deg;
}a[5050];

int cmp(node a, node b){
	return a.deg > b.deg;
}

int _1;
int deg[5050];
vector<int>p,p1;
int sum;
int main(){
	n = read();
	for(int i = 1; i <= n; i++){
		a[i].deg = read();
		a[i].id = i;
		deg[i] = a[i].deg;
		if(a[i].deg == 1){
			_1++;
			p1.push_back(a[i].id);
		}
		else{
			sum += deg[i];
		}
	}
	if(n - _1 == 1){
		;
	}
	else if(n - _1 == 2){
		sum -= 2;
	}
	else{
		sum -= 2 + (n - _1 - 2) * 2;
	}
	if(_1 > sum){
		cout << "NO" << endl;
		return 0;
	}
	sort(a + 1, a + 1 + n, cmp);
	if(n == 2){
		cout << "YES 1"<<endl;
		cout << 1 << endl;
		cout << a[1].id << " " << a[2].id << endl;
	}
	else if(n == 3){
		cout << "YES 2"<<endl;
		cout << 2 << endl;
		cout << a[1].id << " " << a[2].id << endl;
		cout << a[1].id << " " << a[3].id << endl;
	}
	else{
		int st = 0, en = 0;
		for(int i = 1; i <= n && a[i].deg > 1; i++){
			if(i == 1){
				st = a[i].id;
			}
			if(i == n || a[i+1].deg == 1){
				en = a[i].id;
			}
			p.push_back(a[i].id);
		}
		int ans = 0;
		ans = p.size()-1;
		ans += min(2, _1);
		cout << "YES " << ans << endl;
		cout << n - 1 << endl;
		for(int i = 1; i < p.size(); i++){
			cout << p[i-1] << " " << p[i] << endl;
			deg[p[i-1]]--;
			deg[p[i]]--;
		}

		for(int i = 0, j = 0; i < p1.size(); i++){
			if(i == 0){
				cout << p1[i] << " " << st << endl;
				deg[st]--;
			}
			else if(i == 1){
				cout << p1[i] << " " << en << endl;
				deg[en]--;
			}
			else{
				if(deg[p[j]] == 0) j++;
				cout << p1[i] << " " << p[j] << endl;
				deg[p[j]]--;
			}
		}
	}


	return 0;
}
