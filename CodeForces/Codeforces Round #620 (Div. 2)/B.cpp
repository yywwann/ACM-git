#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int  n, m, ans;
int  a[200], b[200];
char s[200][200];
bool f[200];
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

inline bool pd(int x, int y) {
  for (int i = 1; i <= m; i++)
    if (s[x][i] != s[y][m - i + 1]) return 0;
  return 1;
}

inline bool ppd(int x)
{
  for (int i = 1; i <= m / 2; i++)
    if (s[x][i] != s[x][m - i + 1]) return 0;
  return 1;
}

int main()
{
  n = read(); m = read();
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i < n; i++)
    if (!f[i]) {
      for (int j = i + 1; j <= n; j++)
        if (pd(i, j)) {
          ans       += 2;
          a[ans / 2] = i;
          b[ans / 2] = j;
          f[i]       = 1; f[j] = 1;
          break;
        }
    }
  for (int i = 1; i <= n; i++)
    if (!f[i]) {
      if (ppd(i)) {
        ans++;
        a[(ans + 1) / 2] = i;
        break;
      }
    }
  printf("%d\n", ans * m);
  for (int i = 1; i <= ans / 2; i++) printf("%s", s[a[i]] + 1);
  if (ans % 2) printf("%s", s[a[(ans + 1) / 2]] + 1);
  for (int i = ans / 2; i >= 1; i--) printf("%s", s[b[i]] + 1);
  printf("\n");
}