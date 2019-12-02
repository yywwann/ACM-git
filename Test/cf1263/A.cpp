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

ll a[4];

int main() {
  for (int _ = read(); _; _--) {
    for (int i = 1; i <= 3; i++) a[i] = read();
    sort(a + 1, a + 1 + 3);
    if (a[1] + a[2] > a[3]) {
      cout << (a[1] + a[2] + a[3]) / 2 << endl;
    }
    else cout << a[1] + a[2] << endl;
  }
  return 0;
}