#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;

int T;
ll n, d;
struct node {
  ll w, m;
  node(){}
  node(ll w,ll m):w(w),m(m){}
  bool operator < (const node m)const{ //定义比较方式，这一步很重要
    return w < m.w;
  }
}a[N];
ll sum[N];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld %lld", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i].w);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i].m);
    sort(a+1, a+1+n);

    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i].m;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      int pos = upper_bound(a+1, a+1+n, node(a[i].w+2*d, 0)) - a - 1;
      ans = max(ans, sum[pos] - sum[i-1]);
    }
    cout << ans << endl;
  }
}
