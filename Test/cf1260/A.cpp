#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 1e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
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

ll n, sum, a[N], ans;

int main() {
  for (int _ = read(); _; _--) {
    n   = read(), sum = read();
    ans = 0;
    for (int i = 1; i <= n; i++) a[i] = 0;
    ll t = sum / n;
    sum -= t * n;
    for (int i = 1; i <= n; i++) a[i] += t;
    for (int i = 1; i <= n && sum > 0; i++, sum--) a[i]++;
    for (int i = 1; i <= n; i++) ans += a[i] * a[i];
    cout << ans << endl;
  }
  return 0;
}