#include <bits/stdc++.h>
using namespace std;

int n, mx, mi, ans, a[100005];
inline int read()
{
  int x = 0, y = 1; char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') y = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48),
    ch                             = getchar();
  return x * y;
}

int main()
{
  int T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    mi = 1000000001;
    mx = -1;
    for (int i = 1; i < n; i++)
      if ((a[i] == -1) && (a[i + 1] != -1)) mi = min(mi, a[i + 1]), mx = max(mx,
                                                                             a[i +
                                                                               1]);
    for (int i = 2; i <= n; i++)
      if ((a[i] == -1) && (a[i - 1] != -1)) mi = min(mi, a[i - 1]), mx = max(mx,
                                                                             a[i -
                                                                               1]);
    if (mx == -1) mx = 1, mi = 1;
    ans = (mi + mx) / 2;
    for (int i = 1; i <= n; i++)
      if (a[i] == -1) a[i] = ans;
    mx = 0;
    for (int i = 2; i <= n; i++) mx = max(mx, abs(a[i] - a[i - 1]));
    printf("%d %d\n", mx, ans);
  }
}