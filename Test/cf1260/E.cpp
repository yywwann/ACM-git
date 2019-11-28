#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 1e6 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
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

ll n, id, vis[N];
struct node {
  ll id, bei;
} a[N];

int cmp(node a, node b) {
  return a.bei < b.bei;
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i].bei = read();
    a[i].id  = i;
    if (a[i].bei == -1) id = i;
  }
  for (int i = 1; i <= id; i++) a[i].bei = 0;
  sort(a + 1, a + 1 + n, cmp);
  ll  ans = 0;
  int l = 1, r = n;
  while (n > 1) {
    ll MAXid = 0, MAXbei = 0;
    for (int i = l; i <= r; i++) {
      if ((a[i].id > MAXid) && (vis[a[i].id] == 0)) {
        MAXid  = a[i].id;
        MAXbei = a[i].bei;
      }
    }
    if (MAXbei == 0) break;
    ans       += MAXbei;
    vis[MAXid] = 1;
    n         /= 2;
    ll t = n - 1;
    while (t > 0) {
      if (vis[a[r].id] == 0) {
        t--;
        vis[a[r].id] = 1;
      }
      r--;
    }
  }
  cout << ans << endl;
  return 0;
}