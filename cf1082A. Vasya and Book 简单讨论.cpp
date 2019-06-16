#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>       //    ____   _   _  __   __
using namespace std;       //   / ___| | | | | \ \ / /
#define ll long long       //  | |     | |_| |  \ V /
const ll INF = 0x3f3f3f3f; //  | |___  |  _  |   | |
const ll N   = 1e5 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 1e9 + 7;
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

ll n, d, x, y;

int main() {
  for (int _ = read(); _; _--) {
    n = read(), x = read(), y = read(), d = read();

    if (abs(x - y) % d == 0) {
      cout << abs(x - y) / d << endl;
    }
    else {
      ll ans1 = 1e17, ans2 = 1e17;

      if ((y - 1) % d == 0) {
        ans1  = (x - 1) / d + (((x - 1) % d == 0) ? 0 : 1);
        ans1 += (y - 1) / d;
      }

      if ((n - y) % d == 0) {
        ans2  = (n - x) / d + (((n - x) % d == 0) ? 0 : 1);
        ans2 += (n - y) / d;
      }

      if ((ans1 == ans2) && (ans1 == 1e17)) {
        cout << -1 << endl;
      }
      else {
        cout << min(ans1, ans2) << endl;
      }
    }
  }
  return 0;
}
