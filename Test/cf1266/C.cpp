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

ll n, m, ans[505][505];

int main() {
  n = read(), m = read();
  if ((n == 1) && (m == 1)) cout << 0 << endl;
  else if (m == 1) {
    ll t = 2;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << t++ << ' ';
      } cout << endl;
    }
  }
  else {
    ll t = n + m;
    for (int i = n + 1, j = 1; i <= n + m; i++, j++) ans[1][j] = i;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        ans[i][j] = ans[i - 1][j] + ans[1][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << ans[i][j] << ' ';
      } cout << endl;
    }
  }

  return 0;
}