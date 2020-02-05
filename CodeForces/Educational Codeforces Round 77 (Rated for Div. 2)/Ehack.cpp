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

ll n, id, vis[N], b[N];
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
    b[i] = i;
  }
  ll ans = INF;
  vector<node> v1, v2, v3;
  do {
    ll tans = 0;
    v1.clear(), v2.clear();
    for (int i = 1; i <= n; i++) v1.push_back(a[b[i]]);
    v3 = v1;
    while (v1.size() > 1) {
      for (int i = 0; i < v1.size(); i += 2) {
        if (v1[i].bei == -1) {
          v2.push_back(v1[i]);
          if (v1[i].id < v1[i + 1].id) tans += v1[i + 1].bei;
        }
        else if (v1[i + 1].bei == -1) {
          v2.push_back(v1[i + 1]);
          if (v1[i].id > v1[i + 1].id) tans += v1[i].bei;
        }
        else if (v1[i].id > v1[i + 1].id) v2.push_back(v1[i]);
        else v2.push_back(v1[i + 1]);
      }
      v1.clear();
      v1 = v2;
      v2.clear();
    }
    ans = min(ans, tans);
    if (tans == 8) {
      for (int i = 0; i < n; i++) {
        cout << v3[i].id << ' ';
      } cout << endl;
      break;
    }

    // cout << tans << endl;
  }
  while (next_permutation(b + 1, b + 1 + n));
  cout << ans << endl;
  return 0;
}