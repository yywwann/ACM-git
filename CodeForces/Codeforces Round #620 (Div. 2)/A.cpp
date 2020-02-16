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

ll x, y, a, b;

int main() {
  for (int _ = read(); _; _--) {
    x = read(), y = read(), a = read(), b = read();
    ll ans = -1;
    if ((y - x) % (a + b) == 0) {
      ans = (y - x) / (a + b);
    }
    cout << ans << '\n';
  }
  return 0;
}