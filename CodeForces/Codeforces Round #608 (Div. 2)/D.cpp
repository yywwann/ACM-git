#include <bits/stdc++.h>
using namespace std;     //     ____   _   _  __   __
#define ll long long     //    / ___| | |_| |   / /
const ll INF = 2e18;     //   | |     |  _  |   V /
const ll N   = 5000 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;  //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll n, m, k, lef[N], vis[N];
struct node {
  ll a, b, c, id;
  bool operator<(const node& r) const {
    return c < r.c;
  }
} w[N];
vector<int> g[N];

int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) {
    w[i].a  = read(), w[i].b = read(), w[i].c = read();
    w[i].id = i;
    lef[i]  = -1;
  }
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (k >= w[i].a) {
      lef[i] = k - w[i].a;
      k     += w[i].b;
    }
    else break;
  }
  if (lef[n] < 0) cout << -1 << endl;
  else {
    int pos = n;
    priority_queue<node> q;
    ll ans = 0;
    ll sum = 0;
    for (int i = n; i >= 1; i--) {
      if (lef[i] == 0) {
        pos = i;
        break;
      }
    }
    for (int i = 1; i <= pos; i++) q.push(w[i]);
    while (pos < n) {
      int tpos = n;
      ll  tlef = INF;
      for (int i = pos + 1; i <= n; i++) {
        if (lef[i] < tlef) {
          tlef = lef[i];
          tpos = i;
        }
      }
      for (int i = pos + 1; i <= tpos; i++) q.push(w[i]);
      for (int i = tpos; i <= n; i++) lef[i] -= tlef;
      sum += tlef;
      pos  = tpos;
      while (tlef-- && !q.empty()) {
        node u = q.top();
        q.pop();
        ans      += u.c;
        vis[u.id] = 1;
      }
      if (tpos == n) break;

      // for (int i = 1; i <= n; i++) cout << lef[i] << ' '; cout << endl;
    }

    // pos = n
    // cout << k << ' ' << sum << endl;

    // for (int i = 1; i <= n; i++) cout << lef[i] << ' '; cout << endl;
    // cout << ans << endl;
    k -= sum;
    g[n].push_back(n);
    while (k) {
      int tk = k;
      int tpos = 1, tc = 0;
      for (int i = 0; i < g[n].size(); i++) {
        node u = w[g[n][i]];
        if ((u.c > tc) && (vis[u.id] == 0)) {
          tc   = u.c;
          tpos = u.id;
        }
      }
      if (tc != 0) {
        k--;
        ans      += tc;
        vis[tpos] = 1;
      }
      if (tk == k) break;
    }
    cout << ans << endl;
  }
  return 0;
}