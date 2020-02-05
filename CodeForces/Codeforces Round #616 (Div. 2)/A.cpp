#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool ff;
int  n, T;
char s[100005];
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
  scanf("%d", &T);
  while (T--)
  {
    ff = 0;
    scanf("%d", &n);
    scanf("%s", s + 1);
    if (n == 1) { printf("-1\n"); continue; }
    for (int i = 2; i <= n; i++)
      if ((s[i] - 48) % 2) {
        for (int j = 1; j < i; j++)
          if ((s[j] - 48) % 2) {
            printf("%c%c\n", s[j], s[i]);
            i  = n + 1;
            ff = 1;
            break;
          }
      }
    if (!ff) printf("-1\n");
  }
}