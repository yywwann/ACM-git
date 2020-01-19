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

ll dp[1005][1005], n, m, sum[1005][1005];
int main()
{
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      sum[i][j] = 1;
    }
  }
  for (int k = 2; k <= m; k++) {
    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= i; j++) {
        sum[i][j] = (sum[i][j] + sum[i + 1][j] +
                     sum[i][j - 1] - sum[i + 1][j - 1] + MOD) % MOD;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      ans += sum[i][j];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}