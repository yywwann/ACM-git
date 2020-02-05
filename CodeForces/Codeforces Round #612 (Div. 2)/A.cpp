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
string s;

int main() {
  for (int _ = read(); _; _--) {
    n = read();
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ll t = 0;
      for (int i = 0; i < n - 1; i++)
        if ((s[i] == 'A') && (s[i + 1] == 'P')) t = 1, s[i + 1] = 'A', i++;
      ans += t;
    }
    cout << ans << endl;
  }
  return 0;
}