#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k, s, ans;
int a[10005];
inline int read()
{
  int x = 0; char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48),
    ch                             = getchar();
  return x;
}

inline bool find(int x)
{
  for (int i = 1; i <= k; i++)
    if (a[i] == x) return 0;
  return 1;
}

int main()
{
  int T = read();
  while (T--)
  {
    n = read();
    s = read();
    k = read();
    for (int i = 1; i <= k; i++) a[i] = read();
    ans = n;
    for (int i = max(1, s - k); i <= min(n, s + k); i++)
      if (find(i)) ans = min(abs(s - i), ans);
    printf("%d\n", ans);
  }
}