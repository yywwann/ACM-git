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

ll n, x;
string s;
ll f() {
  ll sum = 0, ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') sum++;
    else sum--;
    if (sum == x) ans++;
  }
  return ans;
}

int main() {
  for (int _ = read(); _; _--) {
    n = read(), x = read();
    cin >> s;
    ll _1 = 0, _0 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') _1++;
      else _0++;
    }
    ll tt = _0 - _1, ans = 0;
    if (x == 0) ans = 1;
    if (tt == 0) {
      ans = f();
      if (ans > 0) ans = -1;
    } else {
      ll sum = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') sum--;
        else sum++;
        if (((x - sum) % tt == 0) && ((x - sum) / tt >= 0)) ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}

//
// 1 0 0 1 0 | 1 0 0 1 0 | 1 0 0 1 0
// - 1 0 1 0 1 | 0 1 2 1 2 | 1 2 3 2 3