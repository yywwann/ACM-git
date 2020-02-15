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

ll n, m, K;
ll g[1005][1005], dp[50][50];

int check(int x, int y, int xx, int yy) {
  if ()
}

int main() {
  n = read(), m = read(), K = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      g[i][j] = read();
    }
  }
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= K; j++) {
      dp[i][j] = INF;
    }
    dp[i][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[g[i][j]][g[i - 1][j]] != 0) dp[g[i][j]][g[i - 1][j]] = 1;
      if (dp[g[i][j]][g[i + 1][j]] != 0) dp[g[i][j]][g[i + 1][j]] = 1;
      if (dp[g[i][j]][g[i][j - 1]] != 0) dp[g[i][j]][g[i][j - 1]] = 1;
      if (dp[g[i][j]][g[i][j + 1]] != 0) dp[g[i][j]][g[i][j + 1]] = 1;
      if (dp[g[i - 1][j]][g[i][j]] != 0) dp[g[i - 1][j]][g[i][j]] = 1;
      if (dp[g[i + 1][j]][g[i][j]] != 0) dp[g[i + 1][j]][g[i][j]] = 1;
      if (dp[g[i][j - 1]][g[i][j]] != 0) dp[g[i][j - 1]][g[i][j]] = 1;
      if (dp[g[i][j + 1]][g[i][j]] != 0) dp[g[i][j + 1]][g[i][j]] = 1;
    }
  }
  for (int k = 1; k <= K; k++) {
    for (int i = 1; i <= K; i++) {
      for (int j = 1; j <= K; j++) {
        if (dp[i][j] > dp[i][k] + dp[k][j]) {
          // 如果经过下标k顶点路径比原两点间路径更短
          // 将当前两点权值设为更小的那一个
          dp[i][j] = dp[i][k] + dp[k][j];
        }
      }
    }
  }
  for (int i = 1; i <= K; i++) {
    for (int j = 1; j <= K; j++) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  ll q = read();
  while (q--) {
    ll x = read(), y = read(), xx = read(), yy = read();
    ll ans = 0;
    if (x == xx && y == yy) ans = 0;
    else {
      ans = dp[g[x][y]][g[xx][yy]];
      if (ans == 1) {
        if (check(x, y, xx, yy) == 0 || check(xx, yy, x, y) == 0) ans++;
      }
      printf("%lld\n", ans);
    }
    printf("%lld\n", dp[g[x][y]][g[xx][yy]]);
  }
  return 0;
}
