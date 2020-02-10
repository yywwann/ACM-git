#include <cstdio>
#include <algorithm>
#define N 1000005
using namespace std;
double a[N], b[N], ans[N];
int    f[N], n, now;
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
  n = read();
  for (int i = 1; i <= n; i++) ans[i] = (double)read();
  for (int h = 1; h <= 75; h++)
  {
    for (int i = 1; i <= n; i++) a[i] = ans[i];
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
    f[n] = n;
    for (int i = n - 1; i >= 1; i--)
    {
      if (a[i] * (f[i + 1] - i) >= b[f[i + 1]] - b[i]) f[i] = f[i + 1];
      else f[i] = i;
    }
    now = 1;
    while (now <= n)
    {
      for (int i = now; i <= f[now];
           i++) ans[i] = (double)(b[f[now]] - b[now - 1]) /
                         (double)(f[now] - now + 1);
      now = f[now] + 1;
    }
  }
  for (int i = 1; i <= n; i++) printf("%.9lf\n", ans[i]);
}