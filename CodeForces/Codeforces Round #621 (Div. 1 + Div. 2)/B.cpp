#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;


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

int n, x, mx, ans, tans, u;
int main()
{
  int T = read();
  while (T--)
  {
    n    = read(); x = read();
    mx   = 0;
    tans = x + 1;
    for (int i = 1; i <= n; i++)
    {
      u  = read();
      mx = max(mx, u);
      if (x % u == 0) tans = min(tans, x / u);
    }
    ans = x / mx;
    if (ans == 0) ans = 1;
    if (x % mx) ans++;
    if (tans != x + 1) ans = min(ans, tans);
    printf("%d\n", ans);
  }
}