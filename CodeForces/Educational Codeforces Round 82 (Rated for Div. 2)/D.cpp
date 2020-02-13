#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 1e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll n, m, a[N], num[100], n_2[100];

int get_2(ll x) {
  int t = 0;
  while (x) {
    t++;
    x /= 2;
  }
  return t;
}

int main() {
  for (int _ = read(); _; _--) {
    n = read(), m = read();
    for (int i = 0; i <= 99; i++) num[i] = 0, n_2[i] = 0;
    for (int i = 1; i <= m; i++) {
      a[i] = read();
      num[get_2(a[i])]++;
    }
    ll ans = 0, flg = 1;
    ll sum = 0;
    for (int i = 1; i <= m; i++) sum += a[i];
    if (sum < n) flg = 0;
    if (flg) {
      {
        ll t = 0;
        ll N = n;
        while (N) {
          t++;
          if (N % 2 == 1) n_2[t]++;
          N /= 2;
        }
      }
      for (int i = 1; i <= 70; i++) {
        if (n_2[i] == 1) {
          if (num[i] == 0) {
            ll t = -1;
            for (int j = i; j <= 70; j++) {
              t++;
              if (num[j] > 0) {
                num[j]--;
                ans += t;
                break;
              }
              else num[j] = 1;
            }
          }
          else if (num[i] >= 3) num[i + 1] += (num[i] - 1) / 2;
        }
        else {
          if (num[i] >= 2) num[i + 1] += num[i] / 2;
        }
      }
      cout << ans << endl;
    }
    else cout << -1 << endl;
  }
  return 0;
}