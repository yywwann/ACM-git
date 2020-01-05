#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

char s[1005];
int  a[1005], n, p[10000], cnt;
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

inline int pd()
{
  for (int i = 1; i <= n; i++)
    if (a[i]) return 0;
  return 1;
}

int main()
{
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++)
    if (s[i] == 'B') a[i] = 1;
  cnt = 0;
  for (int i = 1; i < n; i++)
    if (a[i]) p[++cnt] = i, a[i] = 0, a[i + 1] = 1 - a[i + 1];
  if (pd()) {
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) printf("%d ", p[i]);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (s[i] == 'W') a[i] = 1;
    else a[i] = 0;
  cnt = 0;
  for (int i = 1; i < n; i++)
    if (a[i]) p[++cnt] = i, a[i] = 0, a[i + 1] = 1 - a[i + 1];
  if (pd()) {
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) printf("%d ", p[i]);
    return 0;
  }
  printf("-1\n");
  return 0;
}