#include <cstdio>
#include <cstring>
#include <algorithm>
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

int n, ans;
int main()
{
  int T = read();
  while (T--)
  {
    n   = read();
    ans = 0;
    while (n >= 10) ans += n / 10 * 10, n -= n / 10 * 9;
    printf("%d\n", ans + n);
  }
}