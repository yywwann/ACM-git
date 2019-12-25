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

ll a, b, c, r;
ll ans = 0;
int main() {
  for (int _ = read(); _; _--) {
    a = read(), b = read(), c = read(), r = read();
    if (a > b) swap(a, b);
    ans = b - a;
    ll l, rr;
    l  = c - r;
    rr = c + r;
    if ((l <= a) && (l <= b) && (rr <= a) && (rr <= b)) ans -= 0;
    else if ((l <= a) && (l <= b) && (rr >= a) && (rr <= b)) ans -= rr - a;
    else if ((l <= a) && (l <= b) && (rr >= a) && (rr >= b)) ans = 0;
    else if ((l >= a) && (l <= b) && (rr >= a) && (rr <= b)) ans -= rr - l;
    else if ((l >= a) && (l <= b) && (rr >= a) && (rr >= b)) ans -= b - l;
    else if ((l >= a) && (l >= b) && (rr >= a) && (rr >= b)) ans -= 0;
    cout << ans << endl;
  }
  return 0;
}