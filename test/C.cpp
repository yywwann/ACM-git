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

int n, m;
int a[105];

int main() {
  for (int _ = read(); _; _--) {
    n = read();

    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + 1 + n);
    int flg = 1;

    if (n >= 2) {
      int d = a[2] - a[1];

      for (int i = 3; i <= n; i++) {
        if (a[i] - a[i - 1] != d) flg = 0;
      }
    }

    if (flg) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
