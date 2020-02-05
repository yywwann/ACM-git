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
const ll N   = 1e5 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 1e9 + 7;
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

ll PowerMod(ll a, ll b, ll c) {
  ll ans = 1;

  a = a % c;

  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % c;
    b = b / 2;
    a = (a * a) % c;
  }
  return ans;
}

string s;

int main() {
  for (int _ = read(); _; _--) {
    cin >> s;
    ll ans = 0;
    ll _0 = 0, _1 = 0;

    for (int i = 0; i < s.size(); i++) {
      if ((s[i] == '1') && (_0 == 0)) continue;

      if (s[i] == '1') {
        _1++;

        if ((i == s.size() - 1) || (s[i + 1] == '0')) {
          ans = (ans + (PowerMod(2, _0, MOD) - 1 + MOD) % MOD * _1 % MOD) % MOD;
          _1  = 0;
        }
      }

      if (s[i] == '0') _0++;
    }
    cout << ans << endl;
  }
}
