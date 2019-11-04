#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 2e5 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    ____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1; ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0'; ch = getchar();
  }
  return x * f;
}

ll n, s;
struct node {
  ll l, r;
} a[N];
int cmp1(node a, node b) {
  if (a.l == b.l) return a.r < b.r;

  return a.l < b.l;
}

bool check(ll x) {
  // if (n == 1) return 1;

  ll sum1 = 0, sum3 = 0, cnt1 = 0, cnt3 = 0;

  for (int i = 1; i <= n; i++) {
    if (a[i].l > x) {
      cnt3++;
      sum3 += a[i].l;
    }
    else if (a[i].r < x) {
      cnt1++;
      sum1 += a[i].l;
    }
  }

  if ((cnt3 <= n / 2) && (cnt1 <= n / 2)) {
    for (int i = 1; i <= n; i++) {
      if ((a[i].l <= x) && (x <= a[i].r)) {
        if (cnt1 < n / 2) sum1 += a[i].l, cnt1++;
        else sum3 += x;
      }
    }

    if (sum1 + sum3 <= s) return 1;
  }

  return 0;
}

int main() {
  for (int _ = read(); _; _--) {
    n = read(), s = read();

    for (int i = 1; i <= n; i++) a[i].l = read(), a[i].r = read();

    if (n == 1) {
      cout << min(s, a[1].r) << endl;
      continue;
    }
    sort(a + 1, a + 1 + n, cmp1); // ???
    ll l = a[n / 2 + 1].l;        // ???
    ll r = s, ans = 0;

    // [l,r]
    while (l <= r) {
      ll mid = (l + r) / 2;

      if (check(mid)) {
        ans = mid;
        l   = mid + 1;
      }
      else r = mid - 1;
    }

    printf("%lld\n", ans);
  }
  return 0;
}
