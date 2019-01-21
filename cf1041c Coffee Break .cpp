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

ll n, m, d;
struct node{
	ll num, id, pos;
	node(){

	}
	node(int _num, int _id, int _pos){
		num = _num;
		id = _id;
		pos = _pos;
	}
	friend bool operator < (node a, node b)
	{
		return a.num > b.num;//结构体中，x小的优先级高
		//return a.num < b.num;//结构体中，x大的优先级高
	}

}a[2*N];

priority_queue<node>q;
bool cmp1(node a, node b){
	return a.num < b.num;
}
bool cmp(node a, node b){
	return a.id < b.id;
}
int cnt = 0;
int main(){
	n = read(), m = read(), d = read();
	for(int i = 1; i <= n; i++){
		a[i].num = read();
		a[i].id = i;
		a[i].pos = 0;
	}
	sort(a + 1, a + 1 + n, cmp1);
	for(int i = 1; i <= n; i++){
		//cout << a[i].num << endl;
		//if(!q.empty()) cout << "q.top = " << q.top().num << endl;
		if(q.empty() || a[i].num - q.top().num <= d){
			cnt ++;
			a[i].pos = cnt;
			q.push(a[i]);
		}
		else{
			a[i].pos = q.top().pos;
			q.pop();
			q.push(a[i]);
		}
	}
	sort(a + 1, a + 1 + n, cmp);
	cout << cnt << endl;
	for(int i = 1; i <= n; i++){
		cout << a[i].pos << ' ';
	}
	return 0;
}
