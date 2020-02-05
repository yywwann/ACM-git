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

/*
        g = gcd(X, Y)
        X = k1 * g
        Y = k2 * g

        k1 + k2 = a / g
        k1 * k2 = b / g
        k1与k2互质
        k1 + k2 与 k1 * k2互质
        gcd(a, b) = g = gcd(X, Y)


 */
ll a, b;

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  while (~scanf("%lld %lld", &a, &b)) {
    ll g    = gcd(a, b);
    ll A    = a / g;
    ll B    = b / g;
    ll deta = A * A - 4 * B;

    if (deta < 0) {
      cout << "No Solution" << endl;
      continue;
    }
    ll t = sqrt(deta);

    if (t * t != deta) {
      cout << "No Solution" << endl;
      continue;
    }
    ll x1  = (A + t) / 2;
    ll x2  = (A - t) / 2;
    ll ans = max(x1, x2);

    if (ans < 0) {
      cout << "No Solution" << endl;
      continue;
    }
    ll Y = ans * g;
    ll X = a - Y;
    cout << X << " " << Y << endl;
  }
  return 0;
}
