#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 2e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll n;

struct node {
  int u, d;
  node() {}
  node(int u0, int d0) : u(u0), d(d0) {}
  bool operator<(const node& a) const {
    return d > a.d; // 最小值优先
  }
};
int  Max, k;
bool vis[N];

vector<node> g[N];


int bfs(int x) {
  priority_queue<node> q;
  q.push(node(x, 0));
  Max = k = 0;
  memset(vis, false, sizeof(vis));
  vis[x] = true;
  while (!q.empty()) {
    node u = q.top();
    q.pop();
    for (int i = 0; i < g[u.u].size(); i++) {
      node v = g[u.u][i];
      if (!vis[v.u]) {
        vis[v.u] = true;
        q.push(node(v.u, u.d + v.d));
      }
    }
    if (u.d > Max) Max = u.d, k = u.u;
  }
  return k;
}

int path[N];
int st, ed;
void dfs(int u, int fa) {
  if (u == ed) {
    path[u] = 1;
  }
  else {
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i].u;
      if (v == fa) continue;
      dfs(v, u);
      if (path[v] == 1) {
        path[u] = 1;
        break;
      }
    }
  }
}

int ans, anspos;
void dfs1(int u, int fa, int len) {
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i].u;
    if (v == fa) continue;
    if (path[v] == 1) {
      dfs1(v, u, 0);
    }
    else {
      if (ans < len + 1) {
        ans    = len + 1;
        anspos = v;
      }
      dfs1(v, u, len + 1);
    }
  }
}

int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    g[u].push_back(node{ v, 1 });
    g[v].push_back(node{ u, 1 });
  }
  st       = bfs(1);
  ed       = bfs(st);
  path[st] = 1;
  dfs(st, 0);

  // for (int i = 1; i <= n; i++) cout << path[i] << ' '; cout << '\n';
  dfs1(st, 0, 0);
  cout << Max + ans << '\n';
  if (anspos == 0) {
    for (int i = 1; i <= n; i++) {
      if ((i != st) && (i != ed)) anspos = i;
    }
  }
  cout << st << ' ' << ed << ' ' << anspos << '\n';
  return 0;
}