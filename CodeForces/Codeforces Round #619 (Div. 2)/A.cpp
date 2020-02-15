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

string a, b, c;

int main() {
  for (int _ = read(); _; _--) {
    cin >> a >> b >> c;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == c[i]) swap(b[i], c[i]);
      else if (b[i] == c[i]) swap(a[i], c[i]);
      else swap(a[i], c[i]);
    }
    if (a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}