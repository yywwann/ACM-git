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

string s;

int main() {
  for (int _ = read(); _; _--) {
    cin >> s;
    ll ans = 0, flg = -1;
    for (int i = 0; i < s.size(); i++) {
      if ((i > 0) && (s[i] == '1') && (s[i - 1] == '0') && (flg != -1)) {
        ans += i - flg - 1;
      }
      if (s[i] == '1') flg = i;
    }
    cout << ans << endl;
  }
  return 0;
}