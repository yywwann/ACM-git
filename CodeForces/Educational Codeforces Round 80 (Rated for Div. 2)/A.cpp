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

ll n, d, f;

ll fun(ll x) {
  ll t = d / (x + 1);
  if (d % (x + 1) != 0) t++;
  return x + t;
}

int main() {
  for (int _ = read(); _; _--) {
    f = 1;
    n = read(), d = read();
    double a = -1, b = (n - 1), c = n - d;
    double t = b * b - 4 * a * c;
    if (t < 0) f = 0;
    else {
      double x = (-b + sqrt(t)) / 2 / a;
      ll     X = x;
      f = 0;
      for (ll i = max(0LL, X - 10000); i < min(n, X + 10000); i++) {
        if (fun(i) <= n) f = 1;
      }
    }
    if (f) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}