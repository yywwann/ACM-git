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
int    len = 1, t, t1;
int main() {
  s = 'a';
  cout << s << endl;
  cin >> t;
  if (t == 0) return 0;
  if (t == 300) {
    len = 300;
    s   = "";
    for (int i = 1; i <= t; i++) s += 'a';
    cout << s << endl;
    cin >> t;
  }
  else {
    len += t;
    for (int i = 1; i <= t; i++) s += 'a';
    cout << s << endl;
    cin >> t;
    if (t == len) {
      s = "";
      for (int i = 1; i <= t - 1; i++) s += 'b';
      cout << s << endl;
      cin >> t;
      return 0;
    }
  }
  t1 = t;
  for (int i = 0; i < len; i++) {
    s[i] = 'b';
    cout << s << endl;
    cin >> t;
    if (t == 0) break;
    if (t >= t1) s[i] = 'a';
    else s[i] = 'b';
    t1 = t;
  }
  return 0;
}