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
const ll N   = 5e4 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 1e8 + 7;
ll read() {
  ll x = 0, f = 1; char ch = getchar();

  while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }

  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

long long encode(long long x) {
  long long code           = 0;
  const long long up_limit = 10000000000000;

  if (x % 2 == 0) {
    while (x < up_limit) {
      code++;
      x += 2;
    }
  }
  else {
    while (x < up_limit) {
      code++;
      x *= 2;
    }
  }

  return code;
}

int main() {
  // cout << encode(30) << endl;
  cout << (10000000000000 - 30) / 2 << endl;
}
