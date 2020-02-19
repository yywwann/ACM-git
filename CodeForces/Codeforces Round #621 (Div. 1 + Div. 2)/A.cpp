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

ll n, d, a[N];

int main() {
  for (int _ = read(); _; _--) {
    n = read(), d = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    while (d--) {
      for (int i = 2; i <= n; i++) {
        if (a[i] > 0) {
          a[i]--;
          a[i - 1]++;
          break;
        }
      }
    }
    cout << a[1] << endl;
  }
  return 0;
}