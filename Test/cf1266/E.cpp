#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 2e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll n, a[N], b[N], ans, sum;
map<ll, map<ll, ll> > mp;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
  for (int _ = read(); _; _--) {
    int u = read(), v = read(), w = read();
    int t = mp[u][v];
    if (t != 0) {
      b[t]--;
      if (b[t] < a[t]) ans--;
    }
    mp[u][v] = w;
    if (w != 0) {
      b[w]++;
      if (b[w] <= a[w]) ans++;
    }
    printf("%lld\n", sum - ans);
  }
  return 0;
}