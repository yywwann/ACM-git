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
const ll N   = 2e5 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 998244353;
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

ll n, b[N], a[N];
vector<ll> p, q;
int main() {
  for (int _ = 1; _; _--) {
    n = read();

    for (int i = 1; i <= n / 2; i++) {
      b[i] = read();
    }

    for (int i = 1; i <= n / 2; i++) {
      if (b[i] == 0) {
        q.push_back(0);
        p.push_back(0);
      }
      else if (i == 1) {
        q.push_back(0);
        p.push_back(b[i]);
      }
      else {
        ll tq = q[q.size() - 1];
        ll tp = p[p.size() - 1];

        if (b[i] - tq > tp) {
          p.push_back(tp);
          q.push_back(b[i] - tp);
        }
        else {
          q.push_back(tq);
          p.push_back(b[i] - tq);
        }
      }
    }

    for (int i = 0; i < q.size(); i++) cout << q[i] << " ";

    for (int i = p.size() - 1; i >= 0; i--) cout << p[i] << " ";
  }
  return 0;
}
