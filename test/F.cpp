#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int  p[30][30], f[30][30], a[30], b[30], tnow, pos, tt;
int  n, m, now;
char s[100005];
inline int js()
{
  int t;

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) p[a[i]][a[j]] = max(i - j, j - i);

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) t += f[a[i]][a[j]] * p[a[i]][a[j]];
  return t;
}

int main()
{
  scanf("%d%d", &n, &m);
  scanf("%s",   s + 1);
  s[0] = s[1];

  //	for (int i=0;i<=n;i++)
  //	printf("%c ",s[i]);
  //	putchar('\n');
  for (int i = 1; i <= n; i++) f[s[i - 1] - 'a'][s[i] - 'a']++;

  for (int i = 1; i <= m; i++) a[i] = i - 1, b[i] = i - 1;
  now = js();

  while (1)
  {
    tnow = now;

    for (int i = 2; i <= m; i++)
    {
      for (int j = 1; j <= m; j++) b[i] = a[i];
      swap(b[1], b[i]);
      tt = js();

      if (tt < tnow) tnow = tt, pos = i;
    }

    if (tnow < now) swap(a[1], a[pos]), now = tnow;
    else break;
  }

  /*	for (int i=0;i<m;i++)
          {
                  for (int j=0;j<m;j++)
                  printf("%d ",p[i][j]);
                  putchar('\n');
          }*/
  printf("%d\n", now);
}
