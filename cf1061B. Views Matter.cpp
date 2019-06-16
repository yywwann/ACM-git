#include <algorithm> //    ____   _   _  __   __
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;       //   / ___| | | | | \ \ / /
#define ll long long       //  | |     | |_| |  \ V /
const ll INF = 0x3f3f3f3f; //  | |___  |  _  |   | |
const ll N   = 1e5 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 1e9 + 7;
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x  = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

ll n, m;
ll a[N];
ll h, sum;
ll ans;

int main() {
  n = read(), m = read();

  for (int i = 1; i <= n; i++) a[i] = read(), h = max(h, a[i]), sum += a[i];

  sort(a + 1, a + 1 + n);
  ll th = 0;

  for (int i = 1; i <= n; i++) {
    // cout << ans << endl;
    if (a[i] == 0) continue;

    if (th == h) {
      ans++;
      continue;
    }

    if (a[i] > th) {
      ans++;
      th++;
    } else {
      ans++;
    }

    if (i == n) {
      ans += h - th;
    }
  }
  cout << sum - ans << endl;
}
