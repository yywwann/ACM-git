#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

struct node {
  ll s, h;
}  c[200005];
ll tim, n, a, b, ans, asum, bsum, acnt, bcnt, le, now;
inline bool cmp(node aa, node bb) {
  return aa.s < bb.s;
}

inline ll read()
{
  ll x = 0; char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48),
    ch                             = getchar();
  return x;
}

int main()
{
  ll T = read();
  while (T--) {
    n    = read(); tim = read();
    a    = read(); b = read();
    asum = 0; bsum = 0;
    ans  = 0;
    for (ll i = 1; i <= n; i++)
    {
      c[i].h = read();
      if (c[i].h) bsum++;
      else asum++;
    }
    acnt = 0; bcnt = 0;
    for (ll i = 1; i <= n; i++) c[i].s = read();
    if (asum * a + bsum * b <= tim) {
      printf("%lld\n", n);
      continue;
    }
    sort(c + 1, c + n + 1, cmp);

    now = 0;
    while (now < n) {
      now++;
      if (acnt * a + bcnt * b < c[now].s) {
        le = c[now].s - 1 - acnt * a - bcnt * b;
        if (le / a <= asum - acnt) ans = max(ans, acnt + bcnt + le / a);
        else ans =
            max(ans,
                asum +
                min(bsum, bcnt + (c[now].s - 1 - asum * a - bcnt * b) / b));
      }
      if (c[now].h) bcnt++;
      else acnt++;
      while (now < n && c[now].s == c[now + 1].s) {
        now++;
        if (c[now].h) bcnt++;
        else acnt++;
      }
    }
    printf("%lld\n", ans);
  }
}