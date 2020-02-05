#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 1e5 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    ____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1; ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0'; ch = getchar();
  }
  return x * f;
}

ll n, m, ans;
vector<int> g[N];
ll pre[N], nxt[N], vis[N], num[N];

void del(int x) {
  nxt[pre[x]] = nxt[x];
  pre[nxt[x]] = pre[x];
}

int main() {
  n = read(), m = read();

  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), g[u].push_back(v), g[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) pre[i] = i - 1, nxt[i] = i + 1;
  nxt[0] = 1, nxt[n] = 0;
  queue<int> q;

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      del(i), vis[i] = 1, ans++, q.push(i);

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int j = 0; j < g[u].size(); j++) num[g[u][j]] = 1;

        for (int j = nxt[0]; j != 0; j = nxt[j])
          if (!vis[j] && !num[j]) vis[j] = 1, del(j), q.push(j);

        for (int j = 0; j < g[u].size(); j++) num[g[u][j]] = 0;
      }
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
