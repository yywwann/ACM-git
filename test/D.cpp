#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |  \ V /
const ll N   = 1e5 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    \____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

ll sum[500000];
ll l, r;
int main()
{
  ll i, j;

  for  (i = 0; i <= 500000; i++) sum[i] = 1;

  for  (i = 2; i + i <= 500000; i++)
  {
    j = i + i;

    while  (j <= 500000)
    {
      sum[j] += i;
      j      += i;
    }
  }
  int ans = 0;
  l = read();
  r = read();

  for (i = l; i <= r; i++)
  {
    if ((sum[i] >= i) && (sum[i] <= 500000) && (sum[sum[i]] == i))
    {
      ans++;

      if (i == sum[i]) printf("%lld\n", i);
      else printf("%lld %lld\n", min(i, sum[i]), max(i, sum[i]));
    }
  }

  if (ans == 0) cout << endl;
  return 0;
}
