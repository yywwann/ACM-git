#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;       //    ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //    | |     |  _  |  \ V /
const ll N   = 5e6 + 5;    //     | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //       \____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

int n, a[N], temp, ans;
int t1[50];

int sol(const int t[], int x) {
  int idx = 1;
  int ans = 0;
  ll  tt  = 1;
  int ttt[50];

  for (int i = 1; i <= 40; i++) {
    ttt[i] = t[i];
  }

  while (x) {
    ttt[idx++] -= x % 2;
    x          /= 2;
  }

  for (int i = 1; i <= 40; i++, tt *= 2) {
    ans += (ttt[i] > 0 ? 1 : 0) * tt;
  }
  return ans;
}

int main() {
  for (int _ = 1; _; _--) {
    n = read();

    for (int i = 1; i <= n; i++) {
      a[i] = read();
      int t   = a[i];
      int idx = 1;

      while (t) {
        t1[idx++] += t % 2;
        t         /= 2;
      }
    }

    for (int i = 1; i <= n; i++) {
      ans = max(ans, sol(t1, a[i]));
    }
    cout << ans << endl;
  }
  return 0;
}

/*

   5
   1 2 4 8 16
 */
