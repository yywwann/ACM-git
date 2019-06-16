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

// 二分答案，每个项目选k人参加
ll n, m;
struct node {
  ll s, r;
} a[N];

ll sum[N];
vector<ll> v[N], s[N];
int cmp(ll a, ll b) {
  return a > b;
}

int main() {
  n = read(), m = read();

  for (int i = 1; i <= n; i++) {
    a[i].s       = read(), a[i].r = read();
    sum[a[i].s] += a[i].r;
    v[a[i].s].push_back(a[i].r);
  }

  for (int i = 1; i <= m; i++) {
    sort(v[i].begin(), v[i].end(), cmp);
    ll t = 0;

    for (int j = 0; j < v[i].size(); j++) {
      t += v[i][j];
      s[j + 1].push_back(t);
    }
  }

  for (int i = 1; i <= n; i++) {
    sort(s[i].begin(), s[i].end(), cmp);
  }
  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    ll t = 0;

    for (int j = 0; j < n / i && j < s[i].size() && s[i][j] > 0; j++) {
      t += s[i][j];
    }

    // cout << i << " " << t << endl;
    ans = max(ans, t);
  }
  cout << ans << endl;

  return 0;
}
