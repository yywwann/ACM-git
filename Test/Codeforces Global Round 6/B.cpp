#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
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

long long n;
int main()
{
  int T = read();
  while (T--)
  {
    scanf("%lld", &n);
    if ((n > 14) && (n % 14 <= 6) && (n % 14 != 0)) printf("YES\n");
    else printf("NO\n");
  }
}