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
#include <algorithm>               //    ____   _   _  __   __
using namespace std;               //   / ___| | | | | \ \ / /
#define ll long long               //  | |     | |_| |  \ V /
const ll INF = 0x3f3f3f3f3f3f3f3f; //  | |___  |  _  |   | |
const ll N   = 1e5 + 5;            //   \____| |_| |_|   |_|
const ll MOD = 1e9 + 7;
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

// SEGT
struct segt {
  struct seg {
    int l, r;
    ll  sum, lz;
    void update(ll v) {
      sum += v;
      lz  += v;
    }
  };

  ll *a;
  seg t[N << 2];

        #define lc x << 1
        #define rc x << 1 | 1
        #define mid ((t[x].l + t[x].r) >> 1)

  inline void modify(ll *arr) {
    a = arr;
  }

  inline void push_up(int x) {
    t[x].sum = max(t[lc].sum, t[rc].sum);
  }

  inline void push_down(int x) {
    ll lz = t[x].lz;

    t[lc].update(lz);
    t[rc].update(lz);
    t[x].lz = 0;
  }

  void build(int x, int l, int r) {
    t[x].l = l, t[x].r = r, t[x].sum = t[x].lz = 0;

    if (l == r) {
      t[x].sum = a[l];
      return;
    }
    build(lc, l, mid); build(rc, mid + 1, r);
    push_up(x);
  }

  void update(int x, int l, int r, ll v) {
    if (l > r) return;

    int L = t[x].l, R = t[x].r;

    if ((l <= L) && (R <= r)) {
      t[x].update(v);
      return;
    }

    if (t[x].lz) push_down(x);

    if (l <= mid) update(lc, l, r, v);

    if (r > mid) update(rc, l, r, v);
    push_up(x);
  }

  ll query(int x, int l, int r) {
    int L = t[x].l, R = t[x].r;

    if ((l <= L) && (R <= r)) return t[x].sum;

    if (t[x].lz) push_down(x);
    ll res = -INF;

    if (l <= mid) res = max(res, query(lc, l, r));

    if (r > mid) res = max(res, query(rc, l, r));
    push_up(x);
    return res;
  }
} tree;

int n, m;
ll  a[N];

int main() {
  for (int _ = read(); _; _--) {
    n = read(), m = read();

    for (int i = 1; i <= n; i++) a[i] = read();

    for (int i = 1; i <= n - 2; i++) a[i] += a[i + 1] + a[i + 2];
    tree.modify(a);
    tree.build(1, 1, n - 2);

    while (m--) {
      int o = read();

      if (o == 1) {
        int l = read(), r = read(), x = read();
        tree.update(1, l,             r - 2,             x);
        tree.update(1, max(1, l - 1), min(n - 2, r - 1), x);
        tree.update(1, max(1, l - 2), min(n - 2, r),     x);
      }
      else {
        int l = read(), r = read();
        cout << tree.query(1, l, r - 2) << endl;
      }
    }
  }
}
