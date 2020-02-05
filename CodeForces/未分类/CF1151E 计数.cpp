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
#include <algorithm>
using namespace std;       //    ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //    | |     |  _  |  \ V /
const ll N   = 1e5 + 5;    //     | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //       \____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

ll n, a[N], ans;

int main() {
  n = read();

  for (int i = 1; i <= n; i++) a[i] = read();

  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) continue;

    if (a[i - 1] < a[i]) ans += (a[i] - a[i - 1]) * (n - a[i] + 1);

    if (a[i - 1] > a[i]) ans += a[i] * (a[i - 1] - a[i]);
  }
  cout << ans << endl;
}

// 以 i 为界分割,求后半部分的贡献
// l * r
