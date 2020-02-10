include<cstdio>
#include <algorithm>
using namespace std;

int n, x[100005], y[100005], xx[100005], yy[100005], xa, xb, ya, yb;
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
  if (n % 2) {
    printf("NO\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
  for (int i = 2; i <= n; i++) xx[i] = x[i] - x[i - 1], yy[i] = y[i] - y[i - 1];
  xx[1] = x[1] - x[n], yy[1] = y[1] - y[n];
  for (int i = 1; i <= n / 2; i++)
  {
    xa = xx[i];
    xb = xx[n / 2 + i];
    ya = yy[i];
    yb = yy[n / 2 + i];
    if ((xa * xa + ya * ya != xb * xb + yb * yb) || (ya * xb != yb * xa)) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES");
}