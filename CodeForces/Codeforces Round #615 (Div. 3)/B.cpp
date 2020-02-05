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

ll n;
struct node {
  ll x, y;
} a[1005];

int cmp(node a, node b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

int main() {
  for (int _ = read(); _; _--) {
    n = read();
    for (int i = 1; i <= n; i++) {
      a[i].x = read();
      a[i].y = read();
    }
    sort(a + 1, a + 1 + n, cmp);
    string ans = "";
    int    flg = 1, x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
      while (a[i].x > x) {
        ans += 'R';
        x++;
      }
      while (a[i].y > y) {
        ans += 'U';
        y++;
      }
      if ((a[i].x == x) && (a[i].y == y));
      else flg = 0;
    }
    if (flg) {
      cout << "YES" << endl;
      cout << ans << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}