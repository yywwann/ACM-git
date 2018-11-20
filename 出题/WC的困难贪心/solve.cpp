#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
#define ll long long
const int N = 1e5;

struct node{
	int A, B;
	friend bool operator < (node a, node b)
    {
        return a.A > b.A;//结构体中，x小的优先级高
    }
}a[N];

struct P{
	int val, pos;
	P(int v, int p){
		val = v;
		pos = p;
	}
	bool operator < (const P& t) const
	{
		if(val == t.val) return pos < t.pos;
		return val < t.val;
	}
};

struct P2{
	int val, pos;
	P2(int v, int p){
		val = v;
		pos = p;
	}
	bool operator < (const P2& t) const
	{
		if(val == t.val) return pos < t.pos;
		return val < t.val;
	}
};

int t;
int n, la, lb;
set<P> s1;
priority_queue<P2> s2;

int slove(int la, int lb){
	s1.clear();
	while(!s2.empty()) s2.pop();
	ll now = 0, ans = 0;
	for(int i = la + 1; i <= n; i++){
		now += a[i].B;
		s1.insert(P(a[i].B, i));
		//cout << i << ' ' << s1.size() << ' ' << s1.begin() -> val << endl;
		if(s1.size() > lb){
			now -= s1.begin() -> val;
			s1.erase(s1.begin());
		}
	}
	for(int i = 1; i <= la; i++){
		s2.push(P2(a[i].B - a[i].A, i));
		//cout << a[i].B - a[i].A << endl;
		now += a[i].A;
	}
	ans = now;
	//cout << ans << endl;
	//cout << s1.size() << endl;
	for(int i = la + 1; i <= min(n, la + lb) && s1.size() > 0; i++){
		set<P>::iterator it = s1.find(P(a[i].B, i));
		if(it != s1.end()){
			now -= it -> val;
			s1.erase(it);
		}
		else{
			it = s1.begin();
			now -= it -> val;
			s1.erase(it);
		}

		s2.push(P2(a[i].B - a[i].A, i));
		//cout << a[i].B - a[i].A << endl;
		now += a[i].A;
		//cout << s2.top().val << endl;
		now += s2.top().val; s2.pop();

		ans = max(ans, now);

	}
	return ans;
}

int main(){
	scanf("%d", &t);
	while(t--){


		scanf("%d %d %d", &n, &la, &lb);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i].A);
			a[i].A = max(a[i].A, 0);
		}
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i].B);
			a[i].B = max(a[i].B, 0);
		}
		sort(a + 1, a + 1 + n);
		ll ans = slove(la, lb);
		cout << ans << endl;
	}
}
