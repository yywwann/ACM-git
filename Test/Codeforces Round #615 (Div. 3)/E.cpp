#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

vector<int> a[200005];
int b[200005];
int tans, ans, n, m;
inline int read()
{
  int x = 0; char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48),
    ch                             = getchar();
  return x;
}

inline int js(int x, int c)
{
  if (x > n * m) return -1;
  if ((x - c) % m == 0) return (x - c) / m + 1;
  return -1;
}

int main()
{
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
  {
    a[i].push_back(0);
    for (int j = 1; j <= m; j++)
    {
      a[i].push_back(js(read(), j));
      if (a[i][j] != -1) a[i][j] = (i - a[i][j] + n) % n;
    }
  }
  for (int i = 1; i <= m; i++)
  {
    for (int j = 0; j < n; j++) b[j] = 0;
    for (int j = 1; j <= n; j++)
      if (a[j][i] != -1) b[a[j][i]]++;
    tans = n;
    for (int j = 0; j < n; j++) tans = min(tans, n - b[j] + j);
    ans += tans;
  }
  printf("%d\n", ans);
}