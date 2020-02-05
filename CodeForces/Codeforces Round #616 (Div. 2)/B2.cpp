#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

bool fb[300005], fc[300005];
int  a[300005], b[300005], c[300005], n;

inline int read()
{
  int x = 0; char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48),
    ch                             = getchar();
  return x;
}

inline bool pd()
{
  for (int i = 1; i <= n; i++)
    if (fb[i] && fc[i]) return 1;
  return 0;
}

int main()
{
  int T = read();
  while (T--)
  {
    n        = read();
    b[0]     = -1;
    c[n + 1] = -1;
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = min(a[i], b[i - 1] + 1);
    for (int i = n; i >= 1; i--) c[i] = min(a[i], c[i + 1] + 1);
    for (int i = 1; i <= n; i++) fc[i] = fb[i] = 0;
    for (int i = 1; i <= n; i++) {
      if (b[i] > b[i - 1]) fb[i] = 1;
      else break;
    }
    for (int i = n; i >= 1; i--) {
      if (c[i] > c[i + 1]) fc[i] = 1;
      else break;
    }
    if (pd()) printf("Yes\n");
    else printf("No\n");
  }
}