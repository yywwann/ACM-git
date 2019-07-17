#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const long long mod = (long long)1e9 + 7;
long long d1[MAXN], d2[MAXN], d3[MAXN]; // 1 id id2
int n, m, T, type, pos;
void pre_sum(long long a[])
{
  for (int i = 1; i <= n; ++i)
  {
    a[i] = (a[i] + a[i - 1]) % mod;
  }
}

int main()
{
  scanf("%d", &T);

  while (T--)
  {
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    memset(d3, 0, sizeof(d3));
    scanf("%d %d", &n, &m);

    while (m--)
    {
      scanf("%d %d", &type, &pos);

      if (type == 1)
      {
        d1[pos]++;
      }

      if (type == 2)
      {
        d2[pos]++;
      }

      if (type == 3)
      {
        d3[pos]++;
        d3[pos + 1]++;
      }
    }
    pre_sum(d1);

    pre_sum(d2);
    pre_sum(d2);

    pre_sum(d3);
    pre_sum(d3);
    pre_sum(d3);

    for (int i = 1; i <= n; ++i)
    {
      printf("%lld%c", (d1[i] + d2[i] + d3[i]) % mod, i == n ? '\n' : ' ');
    }
  }
  return 0;
}
