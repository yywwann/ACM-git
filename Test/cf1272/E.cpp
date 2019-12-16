#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 18;      //   | |     |  _  |   V /
const ll N   = 1e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll n, a[2 * N], ans[2 * N], vis[2 * N];
ll times;
void print() {
  cout << times++ << endl;
  for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << endl;
}

ll dfs(int x) {
  if (x + a[x] <= n) {
    int t = x + a[x];
    if ((a[t] + 1) % 2 == a[x] % 2) {
      ans[x] = 1;
      return 1;
    }
    else if (vis[t] == 0) {
      vis[t] = 1;
      ans[t] = min(ans[t], dfs(t));
    }
    if (ans[t] == -1);
    else if (ans[t] != INF) {
      if (ans[x] == -1) ans[x] = ans[t] + 1;
      ans[x] = min(ans[x], ans[t] + 1);
    }
  }
  if (x - a[x] >= 1) {
    int t = x - a[x];
    if ((a[t] + 1) % 2 == a[x] % 2) {
      ans[x] = 1;
      return 1;
    }
    else if (vis[t] == 0) {
      vis[t] = 1;
      ans[t] = min(ans[t], dfs(t));
    }
    if (ans[t] == -1);
    else if (ans[t] != INF) {
      if (ans[x] == -1) ans[x] = ans[t] + 1;
      ans[x] = min(ans[x], ans[t] + 1);
    }
  }
  if (ans[x] == INF) {
    ans[x] = -1;
    return -1;
  }
  else {
    return ans[x];
  }
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), ans[i] = INF, vis[i] = 0;
  for (int i = 1; i <= n; i++) {
    vis[i] = 1;
    dfs(i);

    // print();
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}