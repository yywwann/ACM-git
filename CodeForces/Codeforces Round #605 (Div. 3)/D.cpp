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

ll n, a[2 * N], ans, dp[2 * N][2];

int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] < a[i]) {
      dp[i][1] = max({ dp[i][1], dp[i - 1][1] + 1 });
      dp[i][0] = max({ dp[i][0], dp[i - 1][0] + 1 });
    }
    else {
      dp[i][1] = 1;
      dp[i][0] = 0;
    }
    if ((i >= 2) && (a[i - 2] < a[i])) {
      dp[i][0] = max({ dp[i][0], dp[i - 2][1] + 1 });
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = max({ ans, dp[i][1], dp[i][0] });
  }
  cout << ans << endl;
  return 0;
}