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
const ll N   = 1e5 + 5;    //     | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //       \____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

int n, ans;
string pic[20];
int    vis[50][50];

int have2(int x, int y) {
  if ((x - 1 >= 0) && (pic[x - 1][y] == '2')) return true;

  if ((y - 2 >= 0) && (pic[x][y - 2] == '2')) return true;

  if ((x + 1 < n) && (pic[x + 1][y] == '2')) return true;

  if ((y + 2 < pic[x].size()) && (pic[x][y + 2] == '2')) return true;

  return false;
}

int have1() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < pic[i].size(); j++) {
      if (pic[i][j] == '1') return true;
    }

    // cout << pic[i] << endl;
  }
  return false;
}

int main() {
  // freopen("/Users/cccccccccchy/Documents/GitHub/ACM-git/test/in.txt", "r",
  // stdin);
  n = ans = 0;

  while (getline(cin, pic[n])) {
    n++;
  }

  // cout << n << endl;
  // for (int i = 0; i < n; i++) {
  //   cout << pic[i] << endl;
  // }
  int flg = true;

  while (flg) {
    flg = false;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < pic[i].size(); j++) {
        if ((pic[i][j] == '1') && have2(i, j)) {
          vis[i][j] = 1;
          flg       = true;
        }
      }
    }

    if (flg) {
      ans++;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < pic[i].size(); j++) {
          if (vis[i][j] == 1) {
            pic[i][j] = '2';
            vis[i][j] = 0;
          }
        }

        // cout << pic[i] << endl;
      }
    }
  }

  if (have1()) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
