#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 5e5 + 10, mod = 998244353;
int n, a[maxn], b[maxn];
pii tr[maxn];
pii f[maxn], g[maxn];
int qpow(int a, int b) {
  int ans = 1, tmp = a;

  for (; b; b >>= 1, tmp = 1ll * tmp * tmp % mod)
    if (b & 1) ans = 1ll * ans * tmp % mod;
  return ans;
}

pii mer(pii a, pii b) {
  if (a.first == b.first) return pii(a.first, (a.second + b.second) % mod);

  return max(a, b);
}

void add(int x, pii a) {
  for (; x <= n; x += x & -x) tr[x] = mer(tr[x], a);
}

pii qry(int x) {
  pii a(0, 0);

  for (; x; x -= x & -x) a = mer(a, tr[x]);
  return a;
}

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);

  for (int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
  pii lis(0, 0);

  for (int i = 1; i <= n; ++i) {
    f[i] = pii(1, 1);
    auto qf = qry(a[i] - 1);
    f[i] = mer(f[i], pii(qf.first + 1, qf.second));
    add(a[i], f[i]);
    lis = mer(lis, f[i]);
  }
  memset(tr, 0, sizeof(tr));

  for (int i = n; i >= 1; --i) {
    g[i] = pii(1, 1);
    auto qf = qry(n + 1 - a[i] - 1);
    g[i] = mer(g[i], pii(qf.first + 1, qf.second));
    add(n + 1 - a[i], g[i]);
  }
  int iv = qpow(lis.second, mod - 2);

  for (int i = 1; i <= n; ++i) {
    int ans = 0;

    if (f[i].first + g[i].first - 1 != lis.first) {
      ans = 0;
    } else {
      ans = 1ll * f[i].second * g[i].second % mod * iv % mod;
    }
    printf("%d ", ans);
  }
}
