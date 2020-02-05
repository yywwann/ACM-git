#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 1e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll a, b, c, d, e, f, ans;

int main() {
  a = read(), b = read(), c = read(), d = read(), e = read(), f = read();
  if (e > f) {
    ans += min(a, d) * e;
    d   -= min(a, d);
    ans += min({ b, c, d }) * f;
    cout << ans << endl;
  }
  else {
    ans += min({ b, c, d }) * f;
    d   -= min({ b, c, d });
    ans += min(a, d) * e;
    cout << ans << endl;
  }
  return 0;
}