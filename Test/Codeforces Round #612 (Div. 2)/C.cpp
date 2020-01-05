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

ll n, a[N], num[N], ans, b[105], dp[105][105][105][2];
ll _1, _2;

ll f(int x) {
  ll __1 = _1, __2 = _2;
  for (int i = 1; i <= n; i++) b[i] = a[i];
  for (int i = 1; i <= n; i++) if (b[i] == 0) {
      if ((x == 1) && (__1 > 0)) b[i] = 1, __1--;
      else if (__2 > 0) b[i] = 2, __2--;
      else b[i] = 1, __1--;
    }
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0) {
      if ((b[i - 1] % 2 == 1) && (__1 > 0)) b[i] = 1, __1--;
      else if (__2 > 0) b[i] = 2, __2--;
      else b[i] = 1, __1--;
    }
  }
  ll tans = 0;
  for (int i = 2; i <= n; i++) {
    if (b[i] % 2 != b[i - 1] % 2) tans++;
  }
  return tans;
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), num[a[i]] = 1;
  for (int i = 1; i <= n; i++) {
    if (num[i] == 0) {
      if (i % 2 == 1) _1++;
      else _2++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= _1; j++) {
      for (int k = 0; k <= _2; k++) {
        dp[i][j][k][0] = dp[i][j][k][1] = INF;
      }
    }
  }
  dp[0][_1][_2][0] = dp[0][_1][_2][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= _1; j++) {
      for (int k = 0; k <= _2; k++) {
        if (a[i] == 0) {
          if (dp[i - 1][j][k][0] != INF) {
            if (k > 0) {
              dp[i][j][k - 1][0] =
                min(dp[i][j][k - 1][0], dp[i - 1][j][k][0]);
            }
            if (j > 0) {
              dp[i][j - 1][k][1] =
                min(dp[i][j - 1][k][1], dp[i - 1][j][k][0] + 1);
            }
          }
          if (dp[i - 1][j][k][1] != INF) {
            if (k > 0) {
              dp[i][j][k - 1][0] =
                min(dp[i][j][k - 1][0], dp[i - 1][j][k][1] + 1);
            }
            if (j > 0) {
              dp[i][j - 1][k][1] =
                min(dp[i][j - 1][k][1], dp[i - 1][j][k][1]);
            }
          }
        }
        else {
          if ((dp[i - 1][j][k][0] != INF) && (a[i] % 2 == 0)) {
            dp[i][j][k][0] = min(dp[i][j][k][0], dp[i - 1][j][k][0]);
          }
          if ((dp[i - 1][j][k][1] != INF) && (a[i] % 2 == 0)) {
            dp[i][j][k][0] = min(dp[i][j][k][0], dp[i - 1][j][k][1] + 1);
          }
          if ((dp[i - 1][j][k][0] != INF) && (a[i] % 2 == 1)) {
            dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j][k][0] + 1);
          }
          if ((dp[i - 1][j][k][1] != INF) && (a[i] % 2 == 1)) {
            dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j][k][1]);
          }
        }
      }
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 0; j <= _1; j++) {
  //     for (int k = 0; k <= _2; k++) {
  //       cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k][0] << ' ' <<
  //         dp[i][j][k][1] << endl;
  //     } cout << endl;
  //     cout << endl << endl;
  //   }
  // }
  cout << min(dp[n][0][0][1], dp[n][0][0][0]) << endl;
  return 0;
}