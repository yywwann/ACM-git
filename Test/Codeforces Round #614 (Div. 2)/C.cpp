#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int  hin, n, q, r, c;
bool f[4][100005];

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
  n = read(); q = read();
  for (int i = 0; i < 4; i++)
    for (int j = 0; j <= n + 3; j++) f[i][j] = 1;
  while (q--)
  {
    r = read(); c = read();
    if (f[r][c]) {
      f[r][c] = 0;
      if ((f[r - 1][c] == 0) || (f[r + 1][c] == 0)) hin++;
      if ((f[r - 1][c - 1] == 0) || (f[r + 1][c - 1] == 0)) hin++;
      if ((f[r - 1][c + 1] == 0) || (f[r + 1][c + 1] == 0)) hin++;
    }
    else {
      f[r][c] = 1;
      if ((f[r - 1][c] == 0) || (f[r + 1][c] == 0)) hin--;
      if ((f[r - 1][c - 1] == 0) || (f[r + 1][c - 1] == 0)) hin--;
      if ((f[r - 1][c + 1] == 0) || (f[r + 1][c + 1] == 0)) hin--;
    }
    if (hin == 0) printf("Yes\n");
    else printf("No\n");
  }
}