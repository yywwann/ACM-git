#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[10], n;

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
    a[1] = read(); a[2] = read(); a[3] = read(); n = read();
    sort(a + 1, a + 4);
    n -= a[3] - a[1];
    n -= a[3] - a[2];
    if ((n < 0) || (n % 3 != 0)) printf("NO\n");
    else printf("YES\n");
  }
}