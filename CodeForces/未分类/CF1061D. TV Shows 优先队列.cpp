#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, M = 1e9 + 7;
int n, x, y, ans;
multiset<int> s;
multiset<int>::iterator it;
struct node {
  int x, y;
} a[N];
int cmp(node x, node y) {
  return x.y > y.y;
}

signed main() {
  scanf("%lld%lld%lld", &n, &x, &y);

  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i].x, &a[i].y);
    (ans += x + y * (a[i].y - a[i].x) % M) %= M;
    s.insert(a[i].x);
  }
  sort(a + 1, a + 1 + n, cmp);

  for (int i = 1; i <= n; i++) {
    int t = a[i].y;
    it = s.upper_bound(t);

    if ((it != s.end()) && (y * (*it - t) < x)) {
      (ans += y * (*it - t) % M + M - x) %= M;
      s.erase(it);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
