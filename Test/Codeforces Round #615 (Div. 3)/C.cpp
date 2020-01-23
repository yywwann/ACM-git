#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n, m, ans[10], cnt;

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
    cnt = 0;
    n   = read();
    m   = int(sqrt(n) + 1);
    for (int i = 2; i <= m; i++)
      if (n % i == 0) {
        cnt++;
        ans[1] = i;
        n     /= i;
        break;
      }
    for (int i = ans[1] + 1; i <= m; i++)
      if (n % i == 0) {
        cnt++;
        ans[2] = i;
        n     /= i;
        break;
      }
    if ((cnt == 2) && (n != ans[2]) && (n != 1) && (n != ans[1])) {
      printf("YES\n");
      printf("%d %d %d\n", ans[1], ans[2], n);
    }
    else printf("NO\n");
  }
}