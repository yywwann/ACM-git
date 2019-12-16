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

ll a, b, c, ans = INF;

int main() {
  for (int _ = read(); _; _--) {
    a   = read(), b = read(), c = read();
    ans = INF;
    for (int i = a - 1; i <= a + 1; i++) {
      for (int j = b - 1; j <= b + 1; j++) {
        for (int k = c - 1; k <= c + 1; k++) {
          ans = min(ans, 1LL * abs(i - j) + abs(i - k) + abs(j - k));
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}