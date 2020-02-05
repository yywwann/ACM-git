#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| |   / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |   V /
const ll N   = 1e5 + 5;    //   | |___  | | | |   | |
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

ll a, b, c;
ll ans;
int main() {
  for (int _ = read(); _; _--) {
    a  = read(), b = read(), c = read();
    a += c;

    if (a > b) {
      int t = (a + b - 1) / 2;
      ans = min(c + 1, t - b + 1);
    }
    else ans = 0;
    cout << ans << endl;
  }
  return 0;
}
