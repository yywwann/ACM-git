#include <bits/stdc++.h>
using namespace std;    //     ____   _   _  __   __
#define ll long long    //    / ___| | |_| |   / /
const ll INF = 2e18;    //   | |     |  _  |   V /
const ll N   = 3e5 + 5; //   | |___  | | | |   | |
const ll MOD = 1e9 + 7; //    ____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}

ll n, a[N], flg, pos;

int check(int x) {
  for (int i = 1; i < x; i++) {
    if (a[i] >= a[i + 1]) return 0;
  }
  for (int i = n; i > x; i--) {
    if (a[i] >= a[i - 1]) return 0;
  }
  return 1;
}

int main() {
  for (int _ = read(); _; _--) {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read() + 1;
    flg  = 1;
    pos  = n;
    a[0] = 0, a[n + 1] = 1e18;
    for (int i = 1; i <= n; i++) {
      if (a[i] >= i) {
        if (i >= a[i + 1]) {
          for (int j = n; j >= i + 1; j--) {
            if (a[j] >= n - j + 1) a[j] = n - j + 1;
            else break;
          }
          pos = i;
          break;
        }
        else {
          a[i] = i;
        }
      }
      else {
        for (int j = n; j >= i; j--) {
          if (a[j] >= n - j + 1) a[j] = n - j + 1;
          else break;
        }
        pos = i - 1;
        break;
      }

      // if ((a[i - 1] >= a[i]) && (a[i] < i - 1)) {
      //   for (int j = n; j >= i; j--) {
      //     if (a[j] >= n - j) a[j] = n - j;
      //     else break;
      //   }
      //   pos = i - 1;
      //   break;
      // }
      // else if (a[i] >= a[i + 1] && a[i] <= n - i) {
      //   for (int j = n; j >= i; j--) {
      //     if (a[j] >= n - j) a[j] = n - j;
      //     else break;
      //   }
      //   pos = i;
      //   break;
      // }
      // else a[i] = i - 1;

      // if (a[i] >= i - 1) a[i] = i - 1;
      // else if ((a[i] <= a[i - 1]) || (a[i] < i - 1)) {
      //   for (int j = n; j >= i; j--) {
      //     if (a[j] >= n - j) a[j] = n - j;
      //     else break;
      //   }
      //   pos = i;
      //   break;
      // }
    }

    // for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
    // cout << pos << endl;
    flg = check(pos);
    if (flg) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}