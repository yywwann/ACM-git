#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

long long xs, ys, ax, ay, bx, by, t;
long long x[60], y[60];
int ans, n;


inline long long dis(int a, int b)
{
  return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

inline int find(int st, int en)
{
  long long tt = t;
  int cnt      = 0;
  if (abs(xs - x[st]) + abs(ys - y[st]) > tt) return 0;
  tt -= abs(xs - x[st]) + abs(ys - y[st]);
  int now = st;
  for (int i = st; i >= en; i--)
  {
    if (dis(now, i) <= tt) tt -= dis(now, i), cnt++, now = i;
    else return cnt;
  }
  for (int i = st + 1; i <= n; i++)
  {
    if (dis(now, i) <= tt) tt -= dis(now, i), cnt++, now = i;
    else return cnt;
  }
  return cnt;
}

int main()
{
  //	freopen("t.txt","r",stdin);
  scanf("%lld%lld%lld%lld%lld%lld", &x[1], &y[1], &ax, &ay, &bx, &by);
  scanf("%lld%lld%lld",             &xs,   &ys,   &t);
  n = 1;
  while (x[n] * ax + bx <= xs + t &&
         y[n] * ay + by <= ys + t) {
    x[n + 1] = x[n] * ax + bx,
    y[n + 1] = y[n] * ay + by,
    n++;
  }

  //	for (int i=1;i<=n;i++)
  //	cout<<x[i]<<' '<<y[i]<<endl;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) ans = max(ans, find(i, j));
  printf("%d\n", ans);
}