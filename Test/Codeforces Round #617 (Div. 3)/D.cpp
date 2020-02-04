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

ll n, a, b, k, h[N], ans;
vector<ll> v;

int main() {
  n = read(), a = read(), b = read(), k = read();
  for (int i = 1; i <= n; i++) {
    h[i] = read();
    if (h[i] % (a + b) == 0) h[i] = a + b;
    else h[i] %= a + b;
    if (h[i] > a) v.push_back(h[i] - a);
    else ans++;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size() && k > 0; i++) {
    ll t = v[i] / a;
    if (v[i] % a != 0) t++;
    if (k >= t) {
      ans++;
      k -= t;
    }
  }
  cout << ans << endl;
  return 0;
}