#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <vector>
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define LL long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define rep(i, a, b) \
  for (int i = a; i <= b; i++)
#define per(i, a, b) \
  for (int i = a; i >= b; i--)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0);
#define bug cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
#define bugc(_) cout << (# _) << " = " << (_) << endl;
using namespace std;
const double eps = 1e-8;
const int    N   = 1e6 + 5;
const int    M   = 1e6 + 5;
const int    INF = 0x3f3f3f3f;

LL sum[N], dp[N], a[N], f[N], ans;

vector<int> v[N];

void dfs(int u, int fa, int path) {
  LL ts = 0;

  dp[u]  = a[u] * path;
  sum[u] = a[u];

  for (int i = 0; i < v[u].size(); i++) {
    int t = v[u][i];

    if (t == fa) continue;
    f[t] = u;
    dfs(t, u, path + 1);
    sum[u] += sum[t];
    dp[u]  += dp[t];
  }
}

void ddd(int x, int fa) {
  for (int i = 0; i < v[x].size(); i++) {
    int u = v[x][i];

    if (u == fa) continue;
    dp[u] = dp[f[u]] + sum[1] - 2 * sum[u];
    ans   = max(ans, dp[u]);
    ddd(u, x);
  }
}

int main() {
  FAST_IO;
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0, 0);
  ans = dp[1];
  ddd(1, 0);

  //    for(int i=2;i<=n;i++){
  //            dp[i] = dp[f[i]] + sum[1] - 2*sum[i];
  //            ans = max(ans,dp[i]);
  // //		LL res=dp[i]+dp[f[i]]-dp[i]+sum[1]-sum[i];
  // //		ans=max(ans,res);
  // //		cout<<dp[f[i]]<<" "<<dp[i]<<" "<<sum[1]<<" "<<sum[i]<<"
  // "<<res<<endl;
  //    }
  cout << ans << endl;
  return 0;
}
