#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>       //    ____   _   _  __   __
using namespace std;       //   / ___| | | | | \ \ / /
#define ll long long       //  | |     | |_| |  \ V /
const ll INF = 0x3f3f3f3f; //  | |___  |  _  |   | |
const ll N   = 1e5 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 1e9 + 7;
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

int n, a[505], dp[50005];

int main() {
  for (int _ = read(); _; _--) {
    n = read();

    for (int i = 1; i <= n; i++) a[i] = read();

    for (int i = 1; i <= 50000; i++) dp[i] = 0;
    sort(a + 1, a + 1 + n);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
      if (dp[a[i]] == 1) continue;
      dp[a[i]] = 1;
      ans++;

      for (int j = a[i]; j <= 50000; j++) {
        if (dp[j - a[i]] == 1) dp[j] = 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
