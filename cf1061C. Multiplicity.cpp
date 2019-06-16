#include <algorithm> //    ____   _   _  __   __
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
using namespace std;       //   / ___| | | | | \ \ / /
#define ll long long       //  | |     | |_| |  \ V /
const ll INF = 0x3f3f3f3f; //  | |___  |  _  |   | |
const ll N   = 1e5 + 5;    //   \____| |_| |_|   |_|
const ll MOD = 1e9 + 7;
ll read() {
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

ll n;
ll a[N];
ll ans;
ll sum[N];

int main() {
  n = read();

  for (int i = 1; i <= n; i++) a[i] = read();

  sum[0] = 1;

  for (int i = 1; i <= n; i++) {
    if (i == 1) sum[i] = 1, ans = 1;
    else {
      for (int j = 1; j * j <= a[i]; j++) {
        ll _1 = 0, _2 = 0;

        if (a[i] % j == 0) {
          _1 = a[i] / j;
          _2 = j;

          if (_1 > _2) swap(_1, _2);

          if (_2 <= i) {
            ans = (ans + sum[_2 - 1]) % MOD;
          }

          if ((_2 != _1) && (_1 <= i)) {
            ans = (ans + sum[_1 - 1]) % MOD;
          }

          // cout << "xxx   " << _1 << " " << _2 << " " << ans << endl;
          // if(_2 <= i) sum[_2]++;
          // if(_2 != _1 && _1 <= i) sum[_1]++;
        }
      }

      for (int j = sqrt(a[i]); j >= 1; j--) {
        ll _1 = 0, _2 = 0;

        if (a[i] % j == 0) {
          _1 = a[i] / j;
          _2 = j;

          if (_1 > _2) swap(_1, _2);

          if (_2 <= i) sum[_2] = (sum[_2] + sum[_2 - 1]) % MOD;

          if ((_2 != _1) && (_1 <= i)) sum[_1] = (sum[_1] + sum[_1 - 1]) % MOD;
        }
      }
    }

    // for(int i = 0; i <= 20 ; i++) cout << sum[i] << " "; cout << endl;
    // cout << a[i] << " " << ans << endl;
  }
  cout << ans % MOD << endl;
}
