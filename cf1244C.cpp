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

ll n, p, w, d;

int main() {
  n = read(), p = read(), w = read(), d = read();

  for (ll v = 0; v < w; v++) {
    if ((p - v * d) % w == 0) {
      ll x = (p - v * d) / w;
      ll y = v;
      ll z = n - x - y;

      if ((z >= 0) && (x >= 0)) {
        cout << x << ' ' << y << ' ' << z << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

/**
 * 如果使用EXGCD 需要使用int_128
 */

/**
 * x * w + y * d = p
 * 若存在一组解
 * x0
 * y0 = k * w + v (0 <= v < w)
 * =>
 *    x0 * w + y0 * d = p
 * => x0 * w + (k * w + v) * d = p
 * => (x0 + k * d) * w + v * d = p
 * =>
 * x = x0 + k * d
 * y = v
 * 枚举v即可
 */
