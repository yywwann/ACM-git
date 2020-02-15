#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
const ll  INF  = 0x3f3f3f3f3f3f3f3f;
ll func(ll n) {
  return n * (n - 1) / 2;
}

int main() {
  // cout<<func(1000000000)<<endl;
  ll  n, m;
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &n, &m);
    ll ans = func(n + 1);
    ll ge, x, y;
    ll lin = n - m;
    ge = lin / (m + 1);
    y  = lin - (m + 1) * ge;
    x  = m + 1 - y;

    // cout<<x<<" "<<y<<" "<<ge<<endl;
    ans -= x * func(ge + 1);
    ans -= y * func(ge + 2);

    // cout<<ans<<endl;
    printf("%lld\n", ans);
  }
  return 0;
}