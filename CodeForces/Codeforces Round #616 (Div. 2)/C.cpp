#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;


int n, ans, m, k, a[4000], st[4000][20];
inline int read()
{
  int x = 0; char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48),
    ch                             = getchar();
  return x;
}

inline int check(int st, int ed, int x) {
  int t = 1000000000;
  for (int i = 0; i <= x; i++) t = min(t, max(a[st + i], a[ed - (x - i)]));
  return t;
}

int main()
{
  int T = read();
  while (T--)
  {
    n = read(); m = read(); k = read();
    if (k >= m) k = m - 1;
    for (int i = 1; i <= n; i++) a[i] = read();
    ans = 0;
    for (int i = 0; i <= k; i++) ans = max(check(i + 1, n - (k - i), m - k - 1),
                                           ans);
    printf("%d\n", ans);
  }
}