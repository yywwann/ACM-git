#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;       //      ____   _   _  __   __
#define ll long long       //    / ___|  | |_| | \ \ / /
const ll INF = 0x3f3f3f3f; //    | |     |  _  |  \ V /
const ll N   = 5e6 + 5;    //    | |___  | | | |   | |
const ll MOD = 1e9 + 7;    //     \____| |_| |_|   |_|
ll read()
{
  ll   x = 0, f = 1;
  char ch = getchar();

  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }

  while (ch >= '0' && ch <= '9') {
    x  = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

string ss;
char   c;
int    h, m, s;

int main()
{
  int t;

  cin >> t;

  while (t--) {
    cin >> ss >> h >> c >> m >> c >> s;
    ll sum = 24 * 60 * 60;
    ll sub = h * 60 * 60 + m * 60 + s;
    ll ans = sum - sub;
    ans %= 100;
    cout << ans << endl;

    cout << (24 * 60 * 60 -)
  }
  return 0;
}

/*

   99
   2019-01-01 00:00:00
   2019-01-01 12:00:12
 */
