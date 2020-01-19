#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

double ans;
int    n;
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
  n = read();
  for (int i = 1; i <= n; i++) ans += 1.00 / (double)i;
  printf("%.12lf\n", ans);
}