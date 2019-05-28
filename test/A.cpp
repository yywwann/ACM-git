#include <bits/stdc++.h>
using namespace std;       //     ____   _   _  __   __
#define ll long long       //    / ___| | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //   | |     |  _  |  \ V /
const ll N = 1e5 + 5;      //   | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //    \____| |_| |_|   |_|
ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

vector<ll>Fac;

int main() {
  for (int _ = 1; _; _--) {
    Fac.push_back(1);
    for (int i = 1; i <= 20; i++) {
      Fac.push_back(Fac[i-1] * i);
    }
    for (int n = 1; n <= 20; n++) {
      for (int i = 0; i <= n; i++) {
        cout << Fac[n] / Fac[i] / Fac[n-i] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
