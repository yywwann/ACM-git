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
#include <algorithm>       //    ____   _   _  __   __
using namespace std;       //   / ___| | | | | \ \ / /
#define ll long long       //  | |     | |_| |  \ V /
const ll INF = 0x3f3f3f3f; //  | |___  |  _  |   | |
const ll N   = 500 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 1e9 + 7;
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

string s;
int    vis[1000];
int    ty;
int main() {
  for (ll _ = read(); _; _--) {
    memset(vis, 0, sizeof(vis));
    cin >> s;
    ty = 0;

    for (int i = 0; i < s.size(); i++) {
      if (vis[s[i]] == 0) ty++;
      vis[s[i]]++;
    }

    if (ty == 1) cout << -1 << endl;
    else {
      for (int i = 'a'; i <= 'z'; i++) {
        while (vis[i]) {
          cout << char(i);
          vis[i]--;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
