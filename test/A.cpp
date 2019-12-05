#include <bits/stdc++.h>
typedef long long ll;
ll t, n, a;
int check(ll x) {
  return n * a - (1 + x) * x / 2 >= n - x;
}

int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &n, &a);
    if (n <= 2LL * a - 1) {
      printf("%lld\n", n);
      continue;
    }
    ll l = 1, r = n;
    ll m, ans;
    while (l <= r) {
      m = (l + r) >> 1;
      if (check(m)) {
        ans = m;
        l   = m + 1;
      }

      // if (2ll * n - m <= 2ll * a * n - m * m) {
      //   ans = m;
      //   l   = m + 1;
      // }
      else  {
        r = m - 1;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}