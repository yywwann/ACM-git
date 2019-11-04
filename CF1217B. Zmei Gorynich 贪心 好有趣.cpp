#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 1e5 + 5;    //   | |___  | | | |   | |
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

ll n, x;
ll d[105], h[105], c[105];

int main() {
  for (int _ = read(); _; _--) {
    n = read(), x = read();

    for (int i = 1; i <= n; i++) {
      d[i] = read(), h[i] = read();
      c[i] = d[i] - h[i];
    }
    sort(d + 1, d + 1 + n);

    if (x <= d[n]) {
      cout << 1 << endl;
      continue;
    }
    sort(c + 1, c + 1 + n);

    if (c[n] <= 0) {
      cout << -1 << endl;
      continue;
    }
    ll ans = 1;
    x -= d[n];
    ll t = x / c[n];

    if (x % c[n] != 0) t++;
    ans += t;
    cout << ans << endl;
  }
  return 0;
}
