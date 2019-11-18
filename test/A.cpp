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

ll n, a[N], b[N];

int main() {
  for (int _ = read(); _; _--) {
    n = read();

    for (int i = 1; i <= n; i++) a[i] = read();

    for (int i = 1; i <= n; i++) b[i] = read();
    int flg = 1;
    int l = n + 1, r = -1;

    for (int i = 1; i <= n; i++) {
      if (a[i] != b[i]) {
        l = min(l, i), r = max(r, i);
      }
    }

    ll t = a[l] - b[l];

    if (t > 0) flg = 0;

    for (int i = l; i <= r; i++) {
      if (a[i] - b[i] != t) flg = 0;
    }


    if (flg) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
