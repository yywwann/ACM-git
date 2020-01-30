#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s[100005], t[100005];
int  n, ans, now, tnow, snow, T, slen, tlen, f[100005][30];
int main()
{
  scanf("%d", &T);
  while (T--)
  {
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    slen = strlen(s + 1);
    tlen = strlen(t + 1);
    for (int i = 1; i <= 26; i++) f[slen][i] = -1;
    for (int i = slen - 1; i >= 0; i--)
    {
      for (int j = 1; j <= 26; j++) f[i][j] = f[i + 1][j];
      f[i][s[i + 1] - 'a' + 1] = i + 1;
    }
    now = 1; ans = 0;
    while (now <= tlen)
    {
      if (f[0][t[now] - 'a' + 1] == -1) {
        ans = -1; break;
      }
      snow = 0;
      ans++;
      while (now <= tlen &&
             f[snow][t[now] - 'a' + 1] != -1) snow = f[snow][t[now] - 'a' + 1],
        now++;
    }
    printf("%d\n", ans);
  }
}