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
const ll N   = 3e5 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 998244353;
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

ll n, m;
vector<int> g[N];
ll   col[N], vis[N];
ll   ji, ou;
bool flg;
ll   ans;

void dfs(int x) {
  if (ans == 0) return;

  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];

    if (col[v] != 0) {
      if (col[x] == col[v]) {
        ans = 0;
        return;
      }
      else continue;
    }
    else if (col[x] == 1) {
      ou++;
      col[v] = 2;
      dfs(v);
    }
    else {
      ji++;
      col[v] = 1;
      dfs(v);
    }
  }
}

ll PowerMod(ll a, ll b, ll c) {
  ll ans = 1;

  a = a % c;

  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % c;
    b = b / 2;
    a = (a * a) % c;
  }
  return ans;
}

int main() {
  for (int _ = read(); _; _--) {
    n = read(), m = read();

    for (int i = 0; i <= n; i++) g[i].clear(), col[i] = 0;

    while (m--) {
      ll u = read(), v = read();
      g[u].push_back(v);
      g[v].push_back(u);
    }

    ans = 1;

    for (int i = 1; i <= n; i++) {
      if (col[i] == 0) {
        ji     = 0, ou = 0;
        col[i] = 1;
        ji++;
        dfs(i);

        if (ans == 0) break;

        // cout << ji << ' ' << ou << endl;
        ll tans1 = 0, tans2 = 0;
        tans1 = PowerMod(2, ji, MOD);
        tans2 = PowerMod(2, ou, MOD);
        ans   = (ans * ((tans1 + tans2) % MOD)) % MOD;
      }
    }

    cout << ans % MOD << endl;
  }
  return 0;
}
