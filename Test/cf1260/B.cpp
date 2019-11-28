#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int T, a, b, aa, bb, y;
int main()
{
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d%d", &aa, &bb);
    a = min(aa, bb);
    b = max(aa, bb);
    y = b - a;
    if (((a - y) % 3 == 0) && (a - y >= 0)) printf("YES\n");
    else printf("NO\n");
  }
}