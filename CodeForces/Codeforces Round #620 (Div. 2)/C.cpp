#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
const ll  INF  = 0x3f3f3f3f3f3f3f3f;
struct node {
  int t, l, r;
} a[maxn];
bool cmp(node x, node y) {
  return x.t < y.t;
}

int main() {
  int q, n, m;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &a[i].t, &a[i].l, &a[i].r);
    }
    sort(a, a + n, cmp);
    int l = m, r = m, pre = 0;
    int flag = 1;
    for (int i = 0; i < n; i++) {
      int x = a[i].l, y = a[i].r, t = a[i].t - pre;
      if (x >= r) {
        if (x - r > t) flag = 0;
        else r = min(y, r + t), l = x;
      }
      else if (y <= l) {
        if (l - y > t) flag = 0;
        else r = y, l = max(x, l - t);
      }
      else {
        if (y >= r) {
          if (x >= l) r = min(r + t, y), l = x;
          else r = min(r + t, y), l = max(l - t, x);
        }
        else {
          if (x >= l) r = y, l = x;
          else l = max(l - t, x), r = y;
        }
      }
      pre = a[i].t;

      // cout<<l<<' '<<r<<endl;
      if (!flag) break;
    }
    if (flag) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}