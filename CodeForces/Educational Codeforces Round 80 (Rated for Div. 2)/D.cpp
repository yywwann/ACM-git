#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
  long long x, v;
} b[2500005];
long long len;
long long a[300005][10], ans, n, m;
inline bool cmp(node aa, node bb)
{
  return aa.v < bb.v;
}

inline long long read()
{
  long long x = 0; char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48),
    ch                             = getchar();
  return x;
}

inline long long find(long long x, long long y)
{
  long long t = 1000000000;
  for (long long i = 1; i <= m; i++) t = min(t, max(a[x][i], a[y][i]));
  return t;
}

inline long long check(long long r)
{
  long long v = b[r].v;
  long long x = b[r].x;
  for (long long i = 1; i <= n; i++)
    if (find(x, i) == v) return i;
  return 0;
}

int main()
{
  n = read(); m = read();
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m;
         j++) a[i][j] = read(), b[++len] = node{ i, a[i][j] };
  sort(b + 1, b + len + 1, cmp);
  long long l = 1, mid, r = len;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid)) ans = mid, l = mid + 1;
    else r = mid - 1;
  }
  printf("%lld %lld\n", b[ans].x, check(ans));
}