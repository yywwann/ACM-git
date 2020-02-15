#include <bits/stdc++.h>
using namespace std;

vector<int> ex[300], ey[300];
char ma[600][600];
int  f[600][600], n, m, x, y, a, b, q;
int  g[1500][1500][4], p;
inline int read()
{
  int x = 0, y = 1; char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') y = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x  = (x << 1) + (x << 3) + (ch ^ 48),
    ch = getchar();
  }
  return x * y;
}

inline void solve()
{
  x = read(); y = read(); a = read(); b = read();
  int len = min(a - x + 1, b - y + 1);
  if (len % 2) len--;
  for (int i = min(p, len); i >= 2; i -= 2) {
    for (int j = 0; j < ex[i].size(); j++)
      if ((ex[i][j] >= x) && (ex[i][j] + i - 1 <= a) && (ey[i][j] >= y) &&
          (ey[i][j] + i - 1 <= b)) {
        printf("%d\n", i * i);
        return;
      }
  }
  printf("0\n");
}

int main()
{
  freopen("t.txt", "r", stdin);
  n = read(); m = read(); q = read();
  for (int i = 1; i <= n; i++) scanf("%s", ma[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      for (int k = 0; k < 4;
           k++) g[i][j][k] = g[i - 1][j][k] + g[i][j - 1][k] - g[i - 1][j - 1][k];
      if (ma[i][j] == 'R') g[i][j][0]++;
      else if (ma[i][j] == 'G') g[i][j][1]++;
      else if (ma[i][j] == 'B') g[i][j][2]++;
      else if (ma[i][j] == 'Y') g[i][j][3]++;
    }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      if ((ma[i][j] == 'R') && (ma[i][j + 1] == 'G') &&
          (ma[i + 1][j + 1] == 'B') && (ma[i + 1][j] == 'Y')) {
        f[i][j] = 2;
        for (int k = 2; k <= n / 2; k++)
        {
          x = i - k + 1; y = j - k + 1;
          a = i; b = j;
          if ((x < 1) || (y < 1)) break;
          if (g[a][b][0] - g[a][y - 1][0] - g[x - 1][b][0] + g[x - 1][y - 1][0] !=
              k * k) break;

          x = i - k + 1; y = j + 1;
          a = i; b = j + k;
          if ((x < 1) || (y < 1)) break;
          if (g[a][b][1] - g[a][y - 1][1] - g[x - 1][b][1] + g[x - 1][y - 1][1] !=
              k * k) break;

          x = i + 1; y = j + 1;
          a = i + k; b = j + k;
          if ((x < 1) || (y < 1)) break;
          if (g[a][b][2] - g[a][y - 1][2] - g[x - 1][b][2] + g[x - 1][y - 1][2] !=
              k * k) break;

          x = i + 1; y = j - k + 1;
          a = i + k; b = j;
          if ((x < 1) || (y < 1)) break;
          if (g[a][b][3] - g[a][y - 1][3] - g[x - 1][b][3] + g[x - 1][y - 1][3] !=
              k * k) break;
          f[i - k + 1][j - k + 1] = k * 2;
        }
      }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      if (f[i][j]) ex[f[i][j]].push_back(i), ey[f[i][j]].push_back(j);

  p = 0;
  for (int i = n; i >= 1; i--)
    if (ex[i].size()) {
      p = i;
      break;
    }
  if (p == 0) {
    for (int i = 1; i <= q; i++) printf("0\n");
    return 0;
  }
  while (q--) solve();
}