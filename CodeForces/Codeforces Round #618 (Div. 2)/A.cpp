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

ll n, a[N], sum, _0, ans;

int main() {
  for (int _ = read(); _; _--) {
    n   = read();
    ans = sum = _0 = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = read();
      if (a[i] == 0) {
        ans++;
        a[i] = 1;
      }
      sum += a[i];
    }
    if (sum == 0) ans++;
    cout << ans << endl;
  }
  return 0;
}