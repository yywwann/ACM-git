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

ll n, sum;


int main() {
  for (int _ = read(); _; _--) {
    sum = 0;
    n   = read();

    // for(int i = 1; i <= n; i++) {
    //  sum += (n / i);
    // }
    ll t = sqrt(n);

    for (int i = 1; i <= t; i++) {
      sum += n / i;
    }
    sum *= 2;
    sum -= t * t;
    cout << sum << endl;
  }
}
