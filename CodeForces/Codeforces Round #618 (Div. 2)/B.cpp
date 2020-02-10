#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[200005];
inline int read()
{
  int x = 0; char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48),
    ch                             = getchar();
  return x;
}

int main()
{
  int T = read();
  while (T--)
  {
    n = read();
    for (int i = 1; i <= 2 * n; i++) a[i] = read();
    sort(a + 1, a + 2 * n + 1),
    printf("%d\n", a[n + 1] - a[n]);
  }
}