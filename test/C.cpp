#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 2e5 + 5;    //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    ____| |_| |_|   |_|
ll read() {
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1; ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0'; ch = getchar();
  }
  return x * f;
}

ll n, m, a[N], sum[N];

int main() {
  n = read(), m = read();

  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);

  for (int i = 1; i <= n; i++) {
    if (i <= m) sum[i] = a[i];
    else sum[i] = sum[i - m] + a[i];
  }
  vector<ll> ans;
  ll t = 0, cnt = 1;

  for (int i = n, j = 0; i >= 1; i--) {
    t += cnt * a[i];
    j++;

    if (j % m == 0) cnt++;
  }

  for (int i = n; i >= 1; i--) {
    ans.push_back(t);
    t -= sum[i];
  }

  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << ' ';
  }
  return 0;
}
