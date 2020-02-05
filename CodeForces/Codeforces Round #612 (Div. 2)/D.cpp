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

ll n, p[N], c[N], ans[N], flg = 1;
vector<int> g[N];

void add(vector<int>& x, vector<int>y) {
  for (int i = 0; i < y.size(); i++) x.push_back(y[i]);
}

vector<int>dfs(int x) {
  vector<int> t;
  for (int i = 0; i < g[x].size(); i++) {
    add(t, dfs(g[x][i]));
  }
  int num = t.size();
  if (num < c[x]) {
    flg = 0;
    return t;
  }
  t.insert(t.begin() + c[x], x);
  return t;
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) p[i] = read(), c[i] = read();
  for (int i = 1; i <= n; i++) g[p[i]].push_back(i);
  for (int i = 0; i < g[0].size(); i++) {
    vector<int> t = dfs(g[0][i]);
    for (int j = 0; j < t.size(); j++) {
      ans[t[j]] = j + 1;
    }
  }
  if (flg) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  }
  else cout << "NO" << endl;
  return 0;
}